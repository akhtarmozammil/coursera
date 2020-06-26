#include <bits/stdc++.h>

using namespace std;

class MaxMatching {
 public:
  void Solve() {
    vector<vector<bool> > adj_matrix = ReadData();
    vector<int> matching = FindMatching(adj_matrix);
    WriteResponse(matching);
  }

 private:
  vector<vector<bool> > ReadData() {
    int num_left, num_right;
    cin >> num_left >> num_right;
    vector<vector<bool> > adj_matrix(num_left, vector<bool>(num_right));
    for (int i = 0; i < num_left; ++i)
      for (int j = 0; j < num_right; ++j) {
        int bit;
        cin >> bit;
        adj_matrix[i][j] = (bit == 1);
      }
    return adj_matrix;
  }

  void WriteResponse(const vector<int>& matching) {
    for (int i = 0; i < matching.size(); ++i) {
      if (i > 0)
        cout << " ";
      if (matching[i] == -1)
        cout << "-1";
      else{
        cout << (matching[i] + 1);
      }
    }
    cout << "\n";
  }

  bool bmp(vector<vector<bool> >& adj_matrix, vector<bool> &visited, vector<int> &crewAssigned, int u,vector<int> &planeHavingCrewNumber){

      for(int v = 0; v<adj_matrix[0].size(); v++){
        if(adj_matrix[u][v] && !visited[v]){
            visited[v] = true;
            if(crewAssigned[v] == -1 || bmp(adj_matrix,visited,crewAssigned,crewAssigned[v],planeHavingCrewNumber)){
                //cout<<"I Am IN\n";
                crewAssigned[v] = u;
                planeHavingCrewNumber[u] = v;
                return true;
            }
        }
      }

      return false;
  }

  vector<int> FindMatching(vector<vector<bool> >& adj_matrix) {
      int n = adj_matrix.size(), m = adj_matrix[0].size();
      vector<int> crewAssigned(m);
      for(int i =0; i<m; i++)
        crewAssigned[i] = -1;
      vector<int> planeHavingCrewNumber(n);
      for(int i =0; i<n; i++)
        planeHavingCrewNumber[i] = -1;

      for(int i =0; i<n; i++){
          vector<bool> visited(m,false);
          bmp(adj_matrix,visited,crewAssigned,i,planeHavingCrewNumber);

          /*cout<<"matrix\n";
          for(int k =0; k<n; k++){
            for(int l =0; l<m; l++){
                cout<<adj_matrix[k][l]<<" ";
            }cout<<endl;
          }cout<<endl;

          cout<<"Plane having crew\n";
          for(int k =0;k<n; k++){
            cout<<planeHavingCrewNumber[k]<<" ";
          }cout<<endl;*/
      }

      /*for(int i =0; i<m; i++){
        if(crewAssigned[i] != -1)
            planeHavingCrewNumber[crewAssigned[i]] = i;
      }*/

      return planeHavingCrewNumber;
  }
};

int main() {
  MaxMatching max_matching;
  max_matching.Solve();
  return 0;
}


















