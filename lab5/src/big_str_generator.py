import os
import random
import string


def generate_random_string(min_length, max_length):
    """Generate a random string of random length within given range."""
    length = random.randint(min_length, max_length)
    letters = string.ascii_letters
    return "".join(random.choice(letters) for i in range(length))


def create_files_with_random_strings(directory, num_files, min_length, max_length):
    """Create files with random strings of varying lengths in a specified directory."""
    if not os.path.exists(directory):
        os.makedirs(directory)

    for i in range(num_files):
        random_string = generate_random_string(min_length, max_length)
        file_path = os.path.join(directory, f"file_{i}.txt")
        with open(file_path, "w") as file:
            file.write(random_string)


# Example usage
directory = "./test_big"
num_files = 100  # Number of files to create
min_length = 10**6  # Minimum length of the random string
max_length = 8 * 10**6  # Maximum length of the random string

create_files_with_random_strings(directory, num_files, min_length, max_length)
