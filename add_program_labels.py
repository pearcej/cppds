#!/usr/bin/env python3
"""
Script to process PreTeXt files and ensure all program elements have proper labels.
"""

import os
from pathlib import Path
from xml.dom import minidom

def get_element_path(element):
    """Return the full path of nested tags leading to this element."""
    path = []
    current = element
    while current is not None:
        if current.nodeType == current.ELEMENT_NODE:
            path.append(current.tagName)
        current = current.parentNode
    return ' > '.join(reversed(path))

def generate_unique_label(program, file_path, used_labels):
    """Generate a unique label for a program element."""
    
    # First check if there's an xml:id we can use
    if program.hasAttribute('xml:id'):
        xml_id = program.getAttribute('xml:id')
        base_label = f"{xml_id}-prog"
    else:
        # Look for parent task or listing with an xml:id or label
        current = program.parentNode
        while current is not None:
            if current.nodeType == current.ELEMENT_NODE:
                if current.tagName in ['task', 'listing']:
                    if current.hasAttribute('xml:id'):
                        base_label = f"{current.getAttribute('xml:id')}-prog"
                        break
                    elif current.hasAttribute('label'):
                        base_label = f"{current.getAttribute('label')}-prog"
                        break
            current = current.parentNode
        else:
            # Fallback: use file name
            base_name = Path(file_path).stem
            base_label = f"{base_name}-prog"
    
    # Ensure uniqueness
    if base_label not in used_labels:
        used_labels[base_label] = 1
        return base_label
    else:
        used_labels[base_label] += 1
        return f"{base_label}-{used_labels[base_label]}"

def process_file(file_path):
    """Process a single PreTeXt file."""
    try:
        with open(file_path, 'r', encoding='utf-8') as file:
            content = file.read()
            
        # Parse the XML
        dom = minidom.parseString(content)
        programs = dom.getElementsByTagName('program')
        changes_made = 0
        used_labels = {}  # Track used labels in this file
        
        # First identify all programs needing labels
        changes = []
        for program in programs:
            if not program.hasAttribute('label'):
                program_label = generate_unique_label(program, file_path, used_labels)
                original_tag = program.toxml().split('>', 1)[0] + '>'
                new_tag = original_tag.rstrip('>')
                if not new_tag.endswith(' '):
                    new_tag += ' '
                new_tag += f'label="{program_label}">'
                changes.append((original_tag, new_tag))
                changes_made += 1
                print(f"{file_path}: Adding label '{program_label}' to {get_element_path(program)}")
        
        # Apply all changes
        if changes_made > 0:
            for original_tag, new_tag in changes:
                content = content.replace(original_tag, new_tag, 1)
            
            with open(file_path, 'w', encoding='utf-8') as file:
                file.write(content)
            
            print(f"{file_path}: Made {changes_made} changes")
            
    except Exception as e:
        print(f"Error processing {file_path}: {str(e)}")

def main():
    """Process all PreTeXt files in the pretext directory."""
    pretext_dir = Path('pretext')
    for file_path in pretext_dir.rglob('*.ptx'):
        process_file(str(file_path))

if __name__ == '__main__':
    main() 