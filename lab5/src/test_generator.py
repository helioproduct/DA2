#!/usr/bin/env python3

import re
import sys
import string
import random

ALPHABET = "abcd"


def get_random_text(text_len=None):
    if text_len is None:
        text_len = random.randint(1, 100)
    return "".join([random.choice(ALPHABET) for _ in range(text_len)])


def get_all_occurrences(text, pattern):
    last_found = -1
    pos = list()
    while True:
        last_found = text.find(pattern, last_found + 1)
        if last_found == -1:
            break
        pos.append(str(last_found + 1))
    return pos


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: {0} <count of tests>".format(sys.argv[0]))
        sys.exit(1)

    count_of_tests = int(sys.argv[1])
    for enum in range(count_of_tests):
        test_file_name = "tests/{:02d}".format(enum + 1)
        with open("{0}.t".format(test_file_name), "w") as output_file, open(
            "{0}.a".format(test_file_name), "w"
        ) as answer_file:
            text = get_random_text()
            pattern_count = random.randint(1, 20)
            output_file.write("{}\n".format(text))
            for cnt in range(pattern_count):
                use_real_pattern = random.choice([True, False])
                if use_real_pattern and len(text) > 3:
                    start_pos = random.randint(0, len(text) - 3)
                    end_pos = random.randint(start_pos + 1, len(text) - 1)
                    pattern = text[start_pos:end_pos]
                else:
                    pattern = get_random_text(random.randint(1, 10))
                pos = get_all_occurrences(text, pattern)
                output_file.write("{}\n".format(pattern))
                if len(pos):
                    answer_file.write("{}: {}\n".format(cnt + 1, ", ".join(pos)))
