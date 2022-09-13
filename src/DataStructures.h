#pragma once
#include <vector>
struct Hit {
  uint32_t id;
  uint8_t det;
  uint8_t plane;
  uint8_t fec;
  uint8_t vmm;
  double readout_time;
  double time;
  uint8_t ch;
  uint16_t pos;
  uint16_t bcid;
  uint16_t tdc;
  uint16_t adc;
  bool over_threshold;
  double chip_time;
};

struct ClusterPlane {
  uint32_t id;
  uint8_t det;
  uint8_t plane;
  uint16_t size;
  uint16_t adc;
  double time;
  double time_utpc;
  double time_charge2;
  double time_algo;
  double pos;
  double pos_utpc;
  double pos_charge2;
  double pos_algo;
  bool plane_coincidence;
  uint16_t max_delta_time;
  uint16_t max_missing_strip;
  uint16_t span_cluster;
  std::vector<double> strips;
  std::vector<double> times;
  std::vector<double> adcs;
};

struct ClusterDetector {
  uint32_t id;
  uint32_t id0;
  uint32_t id1;
  uint32_t id2;
  uint8_t det;
  uint16_t size0;
  uint16_t size1;
  uint16_t size2;
  uint16_t adc0;
  uint16_t adc1;
  uint16_t adc2;
  double pos0;
  double pos1;
  double pos2;
  double time0;
  double time1;
  double time2;
  double pos0_utpc;
  double pos1_utpc;
  double pos2_utpc;
  double time0_utpc;
  double time1_utpc;
  double time2_utpc;
  double pos0_charge2;
  double pos1_charge2;
  double pos2_charge2;
  double time0_charge2;
  double time1_charge2;
  double time2_charge2;
  double pos0_algo;
  double pos1_algo;
  double pos2_algo;
  double time0_algo;
  double time1_algo;
  double time2_algo;
  double dt0;
  double dt1;
  double dt2;
  double delta_plane_0_1;
  double delta_plane_1_2;
  double delta_plane_0_2;
  uint16_t span_cluster0;
  uint16_t span_cluster1;
  uint16_t span_cluster2;
  uint16_t max_delta_time0;
  uint16_t max_delta_time1;
  uint16_t max_delta_time2;
  uint16_t max_missing_strip0;
  uint16_t max_missing_strip1;
  uint16_t max_missing_strip2;
  std::vector<double> strips0;
  std::vector<double> times0;
  std::vector<double> adcs0;
  std::vector<double> strips1;
  std::vector<double> times1;
  std::vector<double> adcs1;
  std::vector<double> strips2;
  std::vector<double> times2;
  std::vector<double> adcs2;
};

using std::string;

using HitTuple = std::tuple<double, uint16_t, uint16_t, uint16_t>;
using ClusterTuple = std::tuple<uint16_t, double, uint16_t, uint16_t>;
using HitContainer = std::vector<HitTuple>;
using ClusterContainer = std::vector<ClusterTuple>;

using ClusterVectorPlane = std::vector<ClusterPlane>;
using ClusterVectorDetector = std::vector<ClusterDetector>;
using HitVector = std::vector<Hit>;
