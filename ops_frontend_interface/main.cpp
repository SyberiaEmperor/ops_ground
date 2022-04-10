
#include<pybind11/pybind11.h>
#include"Frontend/Frontend.h"

namespace py = pybind11;

PYBIND11_MODULE(Frontend, m)
{
	py::enum_<OPS::Frontend::SourceLanguage>(m, "SourceLanguage")
		.value("AutoLanguage", OPS::Frontend::SourceLanguage::AutoLanguage)
		.value("CLanguage", OPS::Frontend::SourceLanguage::CLanguage)
		.value("FortranLanguage", OPS::Frontend::SourceLanguage::FortranLanguage);

	//auto ncm = py::class_ < OPS::NonCopyableMix, std::unique_ptr < OPS::NonCopyableMix, py::nodelete> >(m, "NonCopyableMix");

	py::class_<OPS::Frontend::Frontend>(m, "Frontend")
		.def(py::init<>())
		.def("compileSingleFile", &(OPS::Frontend::Frontend::compileSingleFile))
		.def("getProgramUnit", &(OPS::Frontend::Frontend::getProgramUnit));
}