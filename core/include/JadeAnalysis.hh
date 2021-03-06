#ifndef JADE_JADEAnalysis_HH
#define JADE_JADEAnalysis_HH

#include "JadeSystem.hh"
#include "JadeDataFrame.hh"
#include "JadeCluster.hh"
#include "JadeOption.hh"
#include "TTree.h"
#include "TH2.h"
#include "TFile.h"

#include <string>
#include <chrono>
#include <mutex>
#include <queue>

#include <sys/types.h>
#include <sys/stat.h>

class DLLEXPORT JadeAnalysis{
 public:
  JadeAnalysis(const JadeOption& opt);
  virtual ~JadeAnalysis();
  virtual void Open();
  virtual void Close();
  virtual void Reset();
  virtual void Analysis(JadeDataFrameSP df);
  void Write(JadeDataFrameSP df);
 private:
  TFile* m_fd; 
  JadeOption m_opt;
  size_t m_ev_print;
  size_t m_ev_n;
  double m_distance_cut;
  int m_seed_cut;
  int m_neigh_cut;
  int m_clus_cut;
  int m_clus_size;
  int m_clus_fix_size;
  int m_base_cut;
  int m_base_numbers;
  int m_base_count;
  int m_hist_nbins;
  std::vector<size_t> m_output_clus_size;
  std::shared_ptr<TTree>m_tree_adc; 
  std::shared_ptr<TH2D>m_hist2_clus_size_adc; 
  std::shared_ptr<TH2D>m_hist2_clus_fix_adc; 
  std::shared_ptr<TH1D>m_hist_seed_adc; 
  std::shared_ptr<TH1D>m_hist_clus_adc; 
  std::shared_ptr<TH1D>m_hist_clus_fix_adc; 
  std::vector<int> m_output_seed_adc;
  std::vector<int> m_output_clus_adc;
  std::vector<int> m_output_clus_fix_adc;
  std::vector<int16_t> m_output_base_adc;
  std::vector<int> m_output_pileup_counts;
  std::vector<std::pair<int, int>> m_hit;
  std::vector<int16_t> m_cds_adc;
  std::vector<int16_t> m_raw_adc;
  bool m_disable_file_write;
  bool m_enable_raw_data_write;
  bool m_enable_hit_map_write;
  bool m_enable_tree_write;
  bool m_enable_hist_write;
  bool m_enable_fix_window_clus_write;
  JadeClusterSP m_clus;
};

using JadeAnalysisSP = std::shared_ptr<JadeAnalysis>;

#endif
