#include "Header.hpp"

using namespace std;

class Solution {
	public:
		
		struct Node
		{
			unordered_set<int> neighbor;
			bool isLeaf()const{return neighbor.size()==1;}
		};
		
		vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
			
			vector<int> buffer1;
			vector<int> buffer2;
			vector<int>* pB1 = &buffer1;
			vector<int>* pB2 = &buffer2;
			if(n==1)
			{
				buffer1.push_back(0);
				return buffer1;
			}
			if(n==2)
			{
				buffer1.push_back(0);
				buffer1.push_back(1);
				return buffer1;
			}
			
			// build the graph
			vector<Node> nodes(n);
			for(auto p:edges)
			{
				nodes[p.first].neighbor.insert(p.second);
				nodes[p.second].neighbor.insert(p.first);
			}
			
			// find all leaves
			for(int i=0; i<n; ++i)
			{
				if(nodes[i].isLeaf()) pB1->push_back(i);
			}

			// remove leaves layer-by-layer            
			while(1)
			{
				for(int i : *pB1)
				{
					for(auto n: nodes[i].neighbor)
					{
						nodes[n].neighbor.erase(i);
						if(nodes[n].isLeaf()) pB2->push_back(n);
					}
				}
				if(pB2->empty())
				{
					return *pB1;
				}
				pB1->clear();
				swap(pB1, pB2);
			}
			
		}
	};

ostream& operator<<(ostream& os, vector<int> vec) {
	for (const auto& item : vec) {
		os << item << " ";
	}
	os << endl;
	return os;
}

int main(int argc, char *argv[]) {
	vector<pair<int, int>> edges = {{0,1}, {0,2}, {0,3}, {3,4}};
	Solution s;
	
	vector<int> res = s.findMinHeightTrees(5, edges);
	cout << res;
	return 0;
}