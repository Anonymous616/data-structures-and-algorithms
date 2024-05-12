class Solution {
public:
  struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
      return a.second < b.second;
    }
  };

  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> freq;

    for (int i = 0; i < nums.size(); i++) {
      freq[nums[i]]++;
    }

    vector<int> result;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    // Push to heap
    for (pair<int, int> p : freq)
      pq.push({p.first, p.second});

    // Pop k most frequent
    for (int i = 0; i < k; i++) {
      result.push_back(pq.top().first);
      pq.pop();
    }

    return result;
  }
};