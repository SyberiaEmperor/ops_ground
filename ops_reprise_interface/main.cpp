
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
				.def(py::init<OPS::Reprise::TranslationUnit::SourceLanguage>());

	py::class_<OPS::Reprise::ProgramUnit>(m, "ProgramUnit")
		.def(py::init<>())
		.def("getUnit", (OPS::Reprise::TranslationUnit&(OPS::Reprise::ProgramUnit::*)(int))( &(OPS::Reprise::ProgramUnit::getUnit)));
}