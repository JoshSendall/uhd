//
// Copyright 2011-2014 Ettus Research LLC
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef INCLUDED_LIBUHD_USRP_RX_DSP_CORE_3000_HPP
#define INCLUDED_LIBUHD_USRP_RX_DSP_CORE_3000_HPP

#include <uhd/config.hpp>
#include <uhd/stream.hpp>
#include <uhd/types/ranges.hpp>
#include <uhd/types/stream_cmd.hpp>
#include <uhd/types/wb_iface.hpp>
#include <uhd/property_tree.hpp>
#include <uhd/usrp/fe_connection.hpp>
#include <boost/utility.hpp>
#include <boost/shared_ptr.hpp>
#include <string>

class rx_dsp_core_3000 : boost::noncopyable{
public:
    static const double DEFAULT_CORDIC_FREQ;
    static const double DEFAULT_RATE;

    typedef boost::shared_ptr<rx_dsp_core_3000> sptr;

    virtual ~rx_dsp_core_3000(void) = 0;

    static sptr make(
        uhd::wb_iface::sptr iface,
        const size_t dsp_base,
        const bool is_b200 = false  //TODO: Obsolete this when we switch to the new DDC on the B200
    );

    virtual void set_mux(const uhd::usrp::fe_connection_t& fe_conn) = 0;

    virtual void set_tick_rate(const double rate) = 0;

    virtual void set_link_rate(const double rate) = 0;

    virtual double set_host_rate(const double rate) = 0;

    virtual uhd::meta_range_t get_host_rates(void) = 0;

    virtual double get_scaling_adjustment(void) = 0;

    virtual uhd::meta_range_t get_freq_range(void) = 0;

    virtual double set_freq(const double freq) = 0;

    virtual void setup(const uhd::stream_args_t &stream_args) = 0;

    virtual void populate_subtree(uhd::property_tree::sptr subtree) = 0;
};

#endif /* INCLUDED_LIBUHD_USRP_RX_DSP_CORE_3000_HPP */
