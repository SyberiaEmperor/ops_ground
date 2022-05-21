
#include<pybind11/pybind11.h>
#include"Reprise/Common.h"
#include"Reprise/ParserResult.h"
#include"Frontend/Frontend.h"
namespace py = pybind11;

PYBIND11_MODULE(Reprise, m)
{
	py::class_<OPS::Reprise::CompileResult>(m, "CompileResult")
		.def(py::init<>())
		.def("error_count", &(OPS::Reprise::CompileResult::errorCount))
		.def("get_m_filename", [](const OPS::Reprise::CompileResult& cr)
			{
				return cr.m_fileName;
			})
		.def("set_m_filename", [](OPS::Reprise::CompileResult& cr, const std::string& str)
			{
				cr.m_fileName = str;
			});

			py::class_<OPS::Reprise::TranslationUnit>(m, "TranslationUnit")
				.def(py::init<OPS::Reprise::TranslationUnit::SourceLanguage>())
				.def("getGlobals", (OPS::Reprise::Declarations & (OPS::Reprise::TranslationUnit::*)(void))(&(OPS::Reprise::TranslationUnit::getGlobals)),py::return_value_policy::reference);

	py::class_<OPS::Reprise::ProgramUnit>(m, "ProgramUnit")
		.def(py::init<>())
		.def("getUnit", (OPS::Reprise::TranslationUnit&(OPS::Reprise::ProgramUnit::*)(int))( &(OPS::Reprise::ProgramUnit::getUnit)), py::return_value_policy::reference);

	py::class_<OPS::Reprise::Declarations>(m, "Declarations")
		.def(py::init<>())
		.def("getFirstSubr", (OPS::Reprise::Declarations::SubrIterator (OPS::Reprise::Declarations::*)(void))(&(OPS::Reprise::Declarations::getFirstSubr)));

	py::class_<OPS::Reprise::SubroutineDeclaration>(m, "SubroutineDeclarations")
		.def("getBodyBlock", (OPS::Reprise::BlockStatement& (OPS::Reprise::SubroutineDeclaration::*)(void))(&(OPS::Reprise::SubroutineDeclaration::getBodyBlock)), py::return_value_policy::reference);

	py::class_<OPS::Reprise::DeclIterator<OPS::Reprise::SubroutineDeclaration>>(m, "DeclIterator")
		.def("isValid", &(OPS::Reprise::DeclIterator<OPS::Reprise::SubroutineDeclaration>::isValid))
		.def("dereference", &(OPS::Reprise::DeclIterator<OPS::Reprise::SubroutineDeclaration>::operator*), py::return_value_policy::reference);

	py::class_<OPS::Reprise::BlockStatement::Iterator>(m, "BlockStatementIter")
		.def("isValid",&(OPS::Reprise::BlockStatement::Iterator::isValid))
		.def("goNext", &(OPS::Reprise::BlockStatement::Iterator::goNext));

	py::class_<OPS::Reprise::BlockStatement>(m, "BlockStatement")
		.def("getFirst", (OPS::Reprise::BlockStatement::Iterator(OPS::Reprise::BlockStatement::*)(void))(&(OPS::Reprise::BlockStatement::getFirst)));
}
