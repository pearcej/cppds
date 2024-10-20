
"""This script checks a bunch of informal rules for PreTeXt/Runestone.
It recurses from the current directory looking for ".ptx" files and
parses each passing the parsed XML representation to a bunch of tests.

If all tests pass, the script exits with status 0, and 1 otherwise.
"""

import xml.dom.minidom
import os
from abc import abstractmethod
import sys


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
                    print(f'{fname}: {captioned_thing} is missing caption')


class ImageNeedsDescription(CppsXmlTest):
    """<image> should have a <description> as a child"""
    captioned_things = ('image',)
    @classmethod
    def test_file(cls, fname, doc):
        ret = True
        for captioned_thing in cls.captioned_things:
            for fig in doc.getElementsByTagName(captioned_thing):
                found = False
                for child in fig.childNodes:
                    if child.nodeType != xml.dom.Node.ELEMENT_NODE:
                        continue
                    if child.nodeName == "description":
                        found = True
                if not found:
                    ret = False
                    print(f'{fname}: {captioned_thing} is missing description')
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
        print(f"unique labels: {len(cls.labels)}")
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


ALL_TESTS = CppsXmlTest.__subclasses__()


def handle_file(fname):
    """Run all the tests on the given filename"""
    dom = xml.dom.minidom.parse(fname)
    r = []
    for t in ALL_TESTS:
        r.append(t.test_file(fname, dom))
    return all(r)


def main():
    """run through all of the ptx files running tests"""
    res = []
    for t in ALL_TESTS:
        res.append(t.setup())

    for root, _, files in os.walk("."):
        for fname in files:
            if not fname.endswith('.ptx'):
                continue
            res.append(handle_file(os.path.join(root, fname)))

    for t in ALL_TESTS:
        res.append(t.teardown())

    sys.exit(0) if all(res) else sys.exit(1)

if __name__ == "__main__":
    main()
