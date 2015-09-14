// Source : https://leetcode.com/problems/course-schedule-ii/
// Author : Yuwei Fang
// Date   : 2015-09-10

/********************************************************************************** 
 * 
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have to first 
 * take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, return the 
 * ordering of courses you should take to finish all courses.
 * 
 * There may be multiple correct orders, you just need to return one of them. If it is 
 * impossible to finish all courses, return an empty array.
 * 
 * For example:
 * 2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have finished 
 * course 0. So the correct course order is [0,1]
 * 
 * 4, [[1,0],[2,0],[3,1],[3,2]]
 * There are a total of 4 courses to take. To take course 3 you should have finished 
 * both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 
 * 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
 * 
 * Note:
 * The input prerequisites is a graph represented by a list of edges, not adjacency 
 * matrices. Read more about how a graph is represented.
 * 
 * click to show more hints.
 * 
 * Hints:
 * 
 * This problem is equivalent to finding the topological order in a directed graph. If 
 * a cycle exists, no topological ordering exists and therefore it will be impossible 
 * to take all courses.
 * Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera 
 * explaining the basic concepts of Topological Sort.
 * Topological sort could also be done via BFS.
 * 
 *               
 *               
 * 
 *               
 **********************************************************************************/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int,int>> &prerequisites) {
        vector<int> res;
        if (numCourse == 0)
            return res;

        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> edge;
        for(const auto &a_b : prerequisites) {
            indegree[a_b.first]++;
            edge[a_b.second].push_back(a_b.first);
        }

        queue<int> que;
        for(int i=0; i<numCourses; ++i) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }

        int cnt = 0;
        while (!que.empty()) {
            int course = que.front();
            que.pop();
            res.push_back(course);
            for(const auto &node : edge[course]) {
                if (--indegree[node] == 0) {
                    que.push(node);
                }
            }
            if (++cnt == numCourses)
                break;
        }
        if (cnt == numCourses && que.empty())
            return res;
        else
            return vector<int>{};
    }
};

