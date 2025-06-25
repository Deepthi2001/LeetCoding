class KthLargest {
public:
    int len;
    priority_queue<int, vector<int>, greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        len=k;
        for(int num:nums){ // nlogk
            pq.push(num);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) { 
        pq.push(val);
        if(pq.size()>len) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */