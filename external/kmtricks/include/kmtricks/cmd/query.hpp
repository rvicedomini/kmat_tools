/*****************************************************************************
 *   kmtricks
 *   Authors: T. Lemane
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/

#pragma once
#include <memory>
#include <thread>

#include <spdlog/spdlog.h>


#include <kmtricks/cli/cli_common.hpp>
#include <kmtricks/cmd/cmd_common.hpp>

namespace km {

struct query_options : km_options
{
  std::string query;
  std::string output;
  double threshold;
  double threshold_shared_positions;
  bool nodetail;
  bool check;
  int z;
  std::string display()
  {
    std::stringstream ss;
    ss << this->global_display();
    RECORD(ss, query);
    RECORD(ss, output);
    RECORD(ss, threshold);
    RECORD(ss, threshold_shared_positions);
    RECORD(ss, nodetail);
    RECORD(ss, check);
    RECORD(ss, z);
    std::string ret = ss.str(); ret.pop_back(); ret.pop_back();
    return ret;
  }
};

using query_options_t = std::shared_ptr<struct query_options>;

};