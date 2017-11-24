#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::pair;
using std::make_pair;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  vector<pair<int, long long>> next_free_time;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  int Parent(int i){
	  return (int)((i-1)/2);
  }

  int LeftChild(int i){
	  return (2*i+1); 
  }

  int RightChild(int i){
	  return (2*i+2);
  }

  void SiftDown(int i);

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    
	for (int i = 0; i < num_workers_; ++i){
		next_free_time.push_back(make_pair(i, 0));
	}

    /*for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      int next_worker = 0;
      for (int j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;
    }*/

	for (int j = (int)(num_workers_/2-1); j >= 0; --j){
		    SiftDown(j);
	    }
	for (int i = 0; i < jobs_.size(); ++i){
		assigned_workers_[i] = next_free_time[0].first;
		start_times_[i] = next_free_time[0].second;
		next_free_time[0].second += jobs_[i];
	    //for (int j = (int)(num_workers_/2-1); j >= 0; --j){
		    SiftDown(0);
	    //}
    }
  
  
  
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

void JobQueue:: SiftDown(int i){
	  int minFT = i;
	  
	  int l = LeftChild(i);
	  if (l <= (num_workers_ - 1)){
		  if (next_free_time[l].second < next_free_time[minFT].second || 
			  next_free_time[l].second == next_free_time[minFT].second && next_free_time[l].first < next_free_time[minFT].first){
				  minFT = l;
		  }
	  }
	 
	  int r = RightChild(i);
	  if (r <= (num_workers_ - 1)){
		  if (next_free_time[r].second < next_free_time[minFT].second || 
			  next_free_time[r].second == next_free_time[minFT].second && next_free_time[r].first < next_free_time[minFT].first){
				  minFT = r;
		  }
	  }

	  if (minFT != i){
		  pair<int, long long> tmp = next_free_time[i];
		  next_free_time[i] = next_free_time[minFT];
		  next_free_time[minFT] = tmp;
		  SiftDown(minFT);
	  }
	  return;
  }

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  system("pause");
  return 0;
}
