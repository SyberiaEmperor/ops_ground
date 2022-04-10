
#include "Reprise/Reprise.h"
#include "Frontend/Frontend.h"
#include <OPS_Core/IO.h>


#include <iostream>

using namespace std;
using namespace OPS;
using namespace OPS::Reprise;

int main()
{
	Frontend::Frontend frontend;
	//const std::string input_filepath = OPS::IO::osPathToPosixPath(L"./tests/goto_test.c"); 
	const OPS::Reprise::CompileResult& result = frontend.compileSingleFile("./tests/goto_test.c");
	if (result.errorCount() > 0) { std::cout << result.errorText(); std::cout.flush(); }

	TranslationUnit& unit = frontend.getProgramUnit().getUnit(0);
	Declarations::SubrIterator firstSubr = unit.getGlobals().getFirstSubr();
	if (firstSubr.isValid())
	{
		SubroutineDeclaration& main = *firstSubr;
		cout << main.getDefinition().getType().getParameterCount() << endl;;
		BlockStatement& body = main.getBodyBlock();
		BlockStatement::Iterator stmt = body.getFirst();
		int stmtCount = 0;
		while (stmt.isValid())
		{
			stmtCount += 1;
			stmt.goNext();
		}
	}
	cout << "sfg" << endl;
	system("pause");
	return 0;
}