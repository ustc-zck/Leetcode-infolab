/*输入: 4, [[1,0],[2,0],[3,1],[3,2]]
输出: [0,1,2,3] or [0,2,1,3]
解释: 总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
     因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*回溯*/
void backtrack(vector<int> courses, vector<vector<int>>& prerequisites, int numCourses, vector<int> &track, vector<vector<int>> &res){
    if(track.size() == numCourses){
        res.push_back(track);
        return;
    }
    for(int i = 0; i < courses.size();  i++){
        /*去重*/
        if(find(track.begin(), track.end(), courses[i]) != track.end())
            continue;
        /*去掉非法排列*/
        int flag = 1;
        if(track.size() != 0){
            for(int j = 0; j < track.size(); j++){
                vector<int> temp;
                temp.push_back(track[j]);
                temp.push_back(courses[i]);
                if(find(prerequisites.begin(), prerequisites.end(), temp) != prerequisites.end())
                    flag = 0;
            }
        }
        if(flag == 0)
            continue;
        track.push_back(courses[i]);
        backtrack(courses, prerequisites, numCourses, track, res);
        track.pop_back();
    }
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
    vector<int> courses;
    for(int i = 0; i < numCourses; i++)
        courses.push_back(i);
    
    vector<vector<int>> res;
    vector<int> track;
    
    backtrack(courses, prerequisites, numCourses, track, res);
    if(res.size() == 0)
        return {};
    return res[0];
}

int main(){

    int numCourse = 10;
    vector<vector<int>> prerequisites = {{5,8},{3,5},{1,9},{4,5},{0,2},{7,8},{4,9}};

    vector<int> res = findOrder(numCourse, prerequisites);
    for(auto c : res){
        cout << c << " ";
    }
    cout << endl;
    
    return 0;
}