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
firstSub = tunit.getGlobals().getFirstSubr()

print(firstSub.isValid())

if firstSub.isValid():
    subDecl = firstSub.dereference()
    body = subDecl.getBodyBlock()
    stmt = body.getFirst()
    count = 0
    while stmt.isValid():
        count+=1
        stmt.goNext()

    print(count)
    
