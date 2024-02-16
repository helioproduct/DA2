import argparse

from os import mkdir
from random import randint, choice


def generate_test(file, n: int, m: int):
    file.write(f"{n} {m}\n")
    for _ in range(n):
        line = [choice(("0", "1")) for _ in range(m)]
        file.write("".join(line) + "\n")


if __name__ == "__main__":
    argument_parser = argparse.ArgumentParser("test generator")
    argument_parser.add_argument("tests_amount", default=None, type=int)

    args = argument_parser.parse_args()

    try:
        mkdir("./tests/")
    except:
        pass

    for i in range(args.tests_amount):
        try:
            file = open(f"./tests/test_{i}", "w")
            generate_test(file, 7500, 7500)
            # generate_test(file, randint(1, 8), randint(1, 8))
        except:
            print(f"error with tests/test_{i} ")
