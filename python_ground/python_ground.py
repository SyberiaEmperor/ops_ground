import Reprise
import Frontend

front = Frontend.Frontend()
res = front.compileSingleFile("./tests/goto_test.c",Frontend.SourceLanguage.CLanguage)

print(res.get_m_filename())
print(res.error_count())

if res.error_count()>0:
    print("Error")
    exit(0)

tunit = front.getProgramUnit().getUnit(0)

