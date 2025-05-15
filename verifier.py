"""This script checks a bunch of informal rules for PreTeXt/Runestone.
It recurses from the current directory looking for ".ptx" files and
parses each passing the parsed XML representation to a bunch of tests.

If all tests pass, the script exits with status 0, and 1 otherwise.
"""

import xml.dom.minidom
import os
from abc import abstractmethod
import sys
import argparse

class CppsXmlTest:
    """generic test"""
    @classmethod
    @abstractmethod
    def test_file(cls, fname, doc):
        """Overridden by subclasses, should return true if "fname" passes the test"""

    @classmethod
    def teardown(cls):
        """May be overriden: called after main tests are run"""
        return True

    @classmethod
    def setup(cls):
        """may be overridden: called before any tests are run"""
        return True


class TabNodeIsNotAThing(CppsXmlTest):
    """TabNode is something the automatic conversion tools emitted.
    PreTeXt doesn't actually have the concept of a TabNode per se,
    so everywhere this tag occurs we have to do some manual work.
    """
    @classmethod
    def test_file(cls, fname, doc):
        n = len(doc.getElementsByTagName("TabNode"))
        if n > 0:
            print(f"{fname} has {n} TabNode tags")
        return n == 0


class ProgramInputDeprecated(CppsXmlTest):
    """TabNode is something the automatic conversion tools emitted.
    PreTeXt doesn't actually have the concept of a TabNode per se,
    so everywhere this tag occurs we have to do some manual work.
    """
    @classmethod
    def test_file(cls, fname, doc):
        ok = True
        for prog in doc.getElementsByTagName("program"):
            for child in prog.childNodes:
                if child.nodeType != xml.dom.Node.ELEMENT_NODE:
                    continue
                if child.nodeName == "input":
                    ok = False
                    print(f'{fname}: "program" has deprecated "input" tag (should be "code")')
        return ok


class TagsNeedsCaption(CppsXmlTest):
    """The tags below should have a <caption> elements as a child"""
    captioned_things = ('figure', 'listing')
    @classmethod
    def test_file(cls, fname, doc):
        ret = True
        for captioned_thing in cls.captioned_things:
            for fig in doc.getElementsByTagName(captioned_thing):
                found = False
                for child in fig.childNodes:
                    if child.nodeType != xml.dom.Node.ELEMENT_NODE:
                        continue
                    if child.nodeName == "caption":
                        found = True
                if not found:
                    ret = False
                    print(f'{fname}: {captioned_thing} is missing caption')


class TagsNeedsTitle(CppsXmlTest):
    """The tags below should have a <title> elements as a child"""
    captioned_things = ('table', 'exploration', 'task')
    @classmethod
    def test_file(cls, fname, doc):
        ret = True
        for captioned_thing in cls.captioned_things:
            for fig in doc.getElementsByTagName(captioned_thing):
                found = False
                for child in fig.childNodes:
                    if child.nodeType != xml.dom.Node.ELEMENT_NODE:
                        continue
                    if child.nodeName == "title":
                        found = True
                if not found:
                    ret = False
                    print(f'{fname}: {captioned_thing} is missing title')


class ImageNeedsDescription(CppsXmlTest):
    """<image> should have a <description> as a child"""
    captioned_things = ('image',)
    @classmethod
    def test_file(cls, fname, doc):
        ret = True
        for fig in doc.getElementsByTagName('image'):
            src = fig.getAttribute("source")
            found = False
            for child in fig.childNodes:
                if child.nodeType != xml.dom.Node.ELEMENT_NODE:
                    continue
                if child.nodeName == "description":
                    found = True
            if not found:
                ret = False
                print(f'{fname}: image is missing description: {src}')
        return ret


class LabelsShouldBeUnique(CppsXmlTest):
    """label attributes should be globally unique"""
    labels = {}

    @classmethod
    def test_file(cls, fname, doc):
        for child in doc.childNodes:
            if child.nodeType != xml.dom.minidom.Node.ELEMENT_NODE:
                continue
            cls.check_node(fname, doc, child)

    @classmethod
    def check_node(cls, fname, doc, element):
        """recursively check all nodes in this document for labels"""
        label = element.getAttribute("label")
        if len(label) > 0:
            if label not in cls.labels:
                cls.labels[label] = []
            cls.labels[label].append(fname)

        for child in element.childNodes:
            if child.nodeType != xml.dom.minidom.Node.ELEMENT_NODE:
                continue
            cls.check_node(fname, doc, child)

    @classmethod
    def setup(cls):
        cls.labels = {}
        return True

    @classmethod
    def teardown(cls):
        ok = True
        for k, v in cls.labels.items():
            if len(v) > 1:
                ok = False
                print(f"label {k} is used {len(v)} times")
                for fname in v:
                    print(f"  in {fname}")
        return ok

class TagsNeedLabels(CppsXmlTest):
    """The tags below are supposed to have labels so that Runestone knows
       where to store the user data."""
    labeled_items = ('exercise', 'task')

    @classmethod
    def test_file(cls, fname, doc):
        ret = True

        for labeled_thing in cls.labeled_items:
            for task in doc.getElementsByTagName(labeled_thing):
                label = task.getAttribute("label")
                if len(label) == 0:
                    print(f'{fname}: {labeled_thing} does not have label')
                    ret = False
        return ret

class ActivecodeProgramsNeedLabels(CppsXmlTest):
    """program elements which are activecode should have labels"""
    labeled_items = ('exercise', 'task')

    @classmethod
    def test_file(cls, fname, doc):
        ret = True

        for prog in doc.getElementsByTagName("program"):
            attr = prog.getAttribute("interactive")
            if attr == "activecode":
                label = prog.getAttribute("label")
                if len(label) == 0:
                    print(f'{fname}: program does not have label')
                    ret = False
        return ret

ALL_TESTS = CppsXmlTest.__subclasses__()


def handle_file(fname, tests):
    """Run all the tests on the given filename"""
    dom = xml.dom.minidom.parse(fname)
    r = []
    for t in tests:
        r.append(t.test_file(fname, dom))
    return all(r)


def main():
    """run through all of the ptx files running tests"""

    parser = argparse.ArgumentParser(prog="pretext verifier",
                                     description="PreTeXt XML verifier")
    parser.add_argument('-D', '--disable', action='append',
                        metavar='test',
                        help='disable a test (can be repeated)', default=[])
    parser.add_argument('-L', '--listtests', action='store_true',
                        help="list available tests and exit")
    parser.add_argument('dirs', nargs='*',
                        help="directories to search for ptx files")

    args = parser.parse_args()
    if not args.dirs:
        args.dirs = ["."]

    if args.listtests:
        _ = [print(t.__name__) for t in ALL_TESTS]
        sys.exit(0)

    failed = False
    for x in args.disable:
        if x not in [t.__name__ for t in ALL_TESTS]:
            failed = True
            print(f"No such test: {x}")
    if failed:
        sys.exit(1)

    tests = [t for t in ALL_TESTS if t.__name__ not in args.disable]
    res = []
    for t in tests:
        res.append(t.setup())

    for dir in args.dirs:
        for root, _, files in os.walk(dir):
            for fname in files:
                if not fname.endswith('.ptx'):
                    continue
                res.append(handle_file(os.path.join(root, fname), tests))

    for t in tests:
        res.append(t.teardown())

    sys.exit(0) if all(res) else sys.exit(1)

if __name__ == "__main__":
    main()
