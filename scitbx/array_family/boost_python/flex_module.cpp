/* Copyright (c) 2001-2002 The Regents of the University of California
   through E.O. Lawrence Berkeley National Laboratory, subject to
   approval by the U.S. Department of Energy.
   See files COPYRIGHT.txt and LICENSE.txt for further details.

   Revision history:
     2002 Aug: Copied from cctbx/arraytbx/flexmodule.cpp (rwgk)
     2002 Aug: Created, based on sharedmodule.cpp, shared_bpl.h (rwgk)
 */

#include <scitbx/array_family/flex_grid_accessor.h>
#include <scitbx/boost_python/utils.h>
#include <boost/python/module_init.hpp>
#include <boost/python/scope.hpp>
#include <boost/python/def.hpp>
#include <boost/python/class.hpp>
#include <scitbx/array_family/boost_python/small_conversions.h>
#include <boost/python/return_value_policy.hpp>
#include <boost/python/copy_const_reference.hpp>

namespace scitbx { namespace af { namespace boost_python {

  void wrap_flex_bool();
  void wrap_flex_size_t();
  void wrap_flex_int();
  void wrap_flex_long();
  void wrap_flex_float();
  void wrap_flex_double();
  void wrap_flex_complex_double();
  void wrap_flex_std_string();

namespace {

  //BOOST_PYTHON_MEM_FUN_GENERATOR(flex_grid_last_stubs, last, 1, 1)

  struct flex_grid_wrappers : boost::python::pickle_suite
  {
    typedef flex_grid<> w_t;
    typedef boost::python::class_<w_t> c_w_t;

    static w_t
    set_layout(
      w_t& fg,
      flex_grid_default_index_type const& layout)
    {
      return fg.set_layout(layout);
    }

    static flex_grid_default_index_type
    last_0(w_t const& fg)
    {
      return fg.last();
    }

    static flex_grid_default_index_type
    last_1(w_t const& fg, bool open_range)
    {
      return fg.last(open_range);
    }

    static boost::python::tuple
    getinitargs(w_t const& fg)
    {
      bool open_range = true;
      return boost::python::make_tuple(
        fg.origin(),
        fg.last(open_range),
        open_range);
    }

    static flex_grid_default_index_type
    getstate(w_t const& fg)
    {
      return fg.layout();
    }

    static void
    setstate(w_t& fg, flex_grid_default_index_type const& state)
    {
      fg.set_layout(state);
    }

    static void
    wrap()
    {
      using namespace boost::python;
      typedef return_value_policy<copy_const_reference> copy_const_reference;
      c_w_t("grid",
        args<>())
        .def_init(args<
          flex_grid_default_index_type const&>())
        .def_init(args<
          flex_grid_default_index_type const&,
          flex_grid_default_index_type const&>())
        .def_init(args<
          flex_grid_default_index_type const&,
          flex_grid_default_index_type const&,
          bool>())
        .def("set_layout", flex_grid_wrappers::set_layout)
        .def("nd", &w_t::nd)
        .def("size_1d", &w_t::size_1d)
        .def("origin", &w_t::origin, copy_const_reference())
        .def("grid", &w_t::grid, copy_const_reference())
        .def("last", flex_grid_wrappers::last_0)
        .def("last", flex_grid_wrappers::last_1)
        //.def("last", &w_t::last, flex_grid_last_stubs())
        .def("layout", &w_t::layout, copy_const_reference())
        .def("is_0_based", &w_t::is_0_based)
        .def("is_padded", &w_t::is_padded)
        .def("__call__", &w_t::operator())
        .def("is_valid_index", &w_t::is_valid_index)
        .def("__eq__", &w_t::operator==)
        .def("__ne__", &w_t::operator!=)
        .def_pickle(flex_grid_wrappers())
      ;
    }
  };

  void init_module()
  {
    using namespace boost::python;

    scope().attr("__version__") = scitbx::boost_python::cvs_revision(
      "$Revision$");

    register_flex_grid_default_index_type_conversions();
    flex_grid_wrappers::wrap();

    wrap_flex_bool();
    wrap_flex_size_t();
    wrap_flex_int();
    wrap_flex_long();
    wrap_flex_float();
    wrap_flex_double();
    wrap_flex_complex_double();
    wrap_flex_std_string();
  }

}}}} // namespace scitbx::af::boost_python::<anonymous>

BOOST_PYTHON_MODULE_INIT(flex)
{
  scitbx::af::boost_python::init_module();
}
