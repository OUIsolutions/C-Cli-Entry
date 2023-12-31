
import Build.CToolKit as ct
from Build.full_folder_zip import zip_folder


STARTER = 'CliEntry/CliEntryMain.h'
TEST_NAME  = 'CliEntryTest.h'

OUTPUT_TEST = 'tests/CliEntryTest.h'
OUTPUT = 'CliEntry.h'
ZIP_NAME ='CliEntry'



ct.generate_amalgamated_code(STARTER,OUTPUT_TEST)
test = ct.FolderTestPreset(folder='tests/main_test')
test.generate_ouptut()
test.start_test()

ct.include_code_in_markdown('README.md',save_file=True)

ct.generate_amalgamated_code(STARTER,OUTPUT)


zip_folder(ZIP_NAME)
