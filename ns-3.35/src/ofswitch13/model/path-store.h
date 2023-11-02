/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * The GPLv2 License (GPLv2)
 *
 * Copyright (c) 2023 Pedro M. Ferreira
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http: //www.gnu.org/licenses/>.
 *
 * Author: Pedro M. Ferreira <pedro.m.marques@inesctec.pt>
 */

#ifndef PATH_STORE_H
#define PATH_STORE_H

#include "ns3/ofswitch13-module.h"

namespace ns3
{
  class PathStore: ObjectBase
  {
  public:
    PathStore(); //Constructor
    ~PathStore(); //Destructor
    static TypeId GetTypeId(void);

    void AddPath(std::vector<Ptr<Node>> path);
    std::vector<Ptr<Node>> GetShortestPath() const;
    std::pair<std::vector<Ptr<Node>>, int> GetShortestPathAndDistance() const;
    std::list<std::pair<std::vector<Ptr<Node>>, int>> GetPaths() const;
    std::list<std::pair<std::vector<Ptr<Node>>, int>> GetShortestsPathsInRange(int percentage) const;
    void CalculateDistances();

  private:
    void CleanPaths();
    std::list<std::pair<std::vector<Ptr<Node>>, int>> paths_; // Vector of paths from switch to host
  };
} // namespace ns3

#endif /* PATH_STORE_H */
