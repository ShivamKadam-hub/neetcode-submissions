class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        //using toposort kahns algorithm
        //building a indegree array

        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        for(auto it: prerequisites){
             indegree[it[0]]++;
             adj[it[1]].push_back(it[0]);
        }
        //creating a queue for storing nodes with indegree 0
        queue<int> q;
        for(int i = 0;i<n;i++){
            int it = indegree[i];
            if(it==0) q.push(i);
        }
        int cnt = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            cnt++;

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }


        }

        return cnt==n;

        
    }
};
