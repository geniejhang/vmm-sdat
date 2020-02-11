#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>

#include <thread>   // sleep_for
#include <future>   // async
#include <atomic>   // async
#include <queue>   // async

#include "RootFile.h"
#include "Statistics.h"

class Clusterer {
public:
        Clusterer(Configuration& config, Statistics &stats);


	~Clusterer();

	// Analyzing and storing the hits
        bool AnalyzeHits(double srsTimestamp, uint8_t fecId, 
        uint8_t vmmId, uint16_t chNo, uint16_t bcid, uint16_t tdc, uint16_t adc, bool overThresholdFlag, float chipTime);
       
        // Analyzing and storing the clusters in plane 0 and 1
        void AnalyzeClustersPlane(std::pair<uint8_t, uint8_t> dp);

	//Select hits that are ready to be clustered in time
        bool ChooseHitsToBeClustered(std::pair<uint8_t, uint8_t> dp);

        bool ChooseClustersToBeMatched(std::pair<uint8_t, uint8_t> dp);

        // Matching the clusters that are common between detector planes
        void AnalyzeClustersDetector(uint8_t det);

        int ClusterByTime(std::pair<uint8_t, uint8_t> dp);
        int ClusterByStrip(std::pair<uint8_t, uint8_t> dp,ClusterContainer &cluster, uint16_t maxDeltaTime);
  
        void AlgorithmUTPC(int idx_min_largest_time, int idx_max_largest_time, std::vector<double> & vADC,
                std::vector<double> & vStrips, std::vector<double> & vTimes, double &positionUTPC, double &timeUTPC, 
                double &positionAlgo, double &timeAlgo);

        void MatchClustersDetector(uint8_t det);

	void FinishAnalysis();

#ifdef USE_ROOT
	void createRootFile(string fileName);
#endif
private:
        Configuration& m_config;
        Statistics &m_stats;
      
        int m_lineNr = 0;
        int m_eventNr = 0;
        
        double last_time0 = 0;
        double last_time1 = 0;
        double last_time0_utpc = 0;
        double last_time1_utpc = 0;
        double last_time0_charge2 = 0;
        double last_time1_charge2 = 0;

        uint8_t m_oldVmmId = 0;
        uint8_t m_oldFecId = 0;

        std::map<std::pair<uint8_t,uint8_t>,HitContainer> m_hits;
        std::map<std::pair<uint8_t,uint8_t>,HitContainer> m_hits_new;
        std::map<std::pair<uint8_t,uint8_t>,ClusterVectorPlane> m_clusters;
        std::map<std::pair<uint8_t,uint8_t>,ClusterVectorPlane> m_clusters_new;
        std::map<uint8_t,ClusterVectorDetector> m_clusters_detector;

	int m_cluster_id = 0;
	int m_cluster_detector_id = 0;
       
        RootFile* m_rootFile;

	

};

