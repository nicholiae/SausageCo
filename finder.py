import os

def search_files(directory):
    search_string = "class SmallGuts: Edible_Base"
    
    # Walk through directory and subdirectories
    for root, dirs, files in os.walk(directory):
        # Look for config.cpp files
        for file in files:
            if file.lower() == "config.cpp":
                file_path = os.path.join(root, file)
                try:
                    # Open and read each config.cpp file
                    with open(file_path, 'r', encoding='utf-8') as f:
                        content = f.read()
                        if search_string in content:
                            print(f"Found match in: {file_path}")
                except Exception as e:
                    print(f"Error reading {file_path}: {str(e)}")

if __name__ == "__main__":
    # Get current directory
    current_dir = os.getcwd()
    print(f"Searching in: {current_dir}")
    search_files(current_dir)
