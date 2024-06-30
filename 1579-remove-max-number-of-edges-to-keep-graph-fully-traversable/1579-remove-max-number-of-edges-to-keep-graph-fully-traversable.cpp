class DisjointSet
{
public:
    vector<int> Parent; 
    vector<int> Rank;    
    int components;     

    DisjointSet(int n)
    {
        Rank.resize(n + 1, 0);  
        Parent.resize(n + 1);   
        components = n;         
        for (int i = 0; i <= n; i++)
        {
            Parent[i] = i;     
        }
    }

    
    int FindUltimateParent(int node)
    {
        if (node == Parent[node])  
        {
            return node;
        }
        return (Parent[node] = FindUltimateParent(Parent[node])); 
    }


    void UnionByRank(int u, int v)
    {
        int Ult_U = FindUltimateParent(u);  
        int Ult_V = FindUltimateParent(v);  

       
        if (Ult_U == Ult_V)
        {
            return;
        }

        
        if (Rank[Ult_U] < Rank[Ult_V])
        {
            Parent[Ult_U] = Ult_V;
        }
        else if (Rank[Ult_U] > Rank[Ult_V])
        {
            Parent[Ult_V] = Ult_U;  
        }
        else
        {
            Parent[Ult_V] = Ult_U;  
            Rank[Ult_U]++;
        }
        components--;  
    }

    
    bool isSingleComponent()
    {
        return components == 1;
    }
};

class Solution {
private:
   
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        return a[0] < b[0];
    }

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        sort(edges.rbegin(), edges.rend(), cmp);

        DisjointSet alice(n);
        DisjointSet bob(n);   

        int edgeCount = 0;     

        for (auto &it : edges)
        {
            int type = it[0];
            int u = it[1];
            int v = it[2];

            if (type == 3)
            {
                bool flag = false;

                
                if (alice.FindUltimateParent(u) != alice.FindUltimateParent(v))
                {
                    alice.UnionByRank(u, v);
                    flag = true;
                }

                // For Bob
                if (bob.FindUltimateParent(u) != bob.FindUltimateParent(v))
                {
                    bob.UnionByRank(u, v);
                    flag = true;
                }
                if (flag)
                {
                    edgeCount++;
                }
            }
            else if (type == 2)
            {
                bool flag = false;

               
                if (bob.FindUltimateParent(u) != bob.FindUltimateParent(v))
                {
                    bob.UnionByRank(u, v);
                    flag = true;
                }
                if (flag)
                {
                    edgeCount++;  
                }
            }
            else
            {
                bool flag = false;
                
                if (alice.FindUltimateParent(u) != alice.FindUltimateParent(v))
                {
                    alice.UnionByRank(u, v);
                    flag = true;
                }
                if (flag)
                {
                    edgeCount++;  
                }
            }
        }

        
        if (alice.isSingleComponent() && bob.isSingleComponent())
        {
            return edges.size() - edgeCount;  
        }
        return -1;  
    }
};