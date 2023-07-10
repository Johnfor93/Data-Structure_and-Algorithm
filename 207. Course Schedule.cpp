class Solution {
public:

    /*
        Problem can finished with cycle detecting on directed graph.

        The problem defined as directed graph because we know on the problem E(x,y) is not equal with E(y,x).
        The course can be finished if and only if the graph doesn't contain cycle.
    */

    /* 
        isVisited is array for save all vertex that visited in different tree
        curStack is array for save all vertex that visited only in one tree

        Case:
        1--2--3
        4--5

        when we traverse first tree with vertex one
        the value of index 1,2,3 will be set true even the function done
        but for curStack will be set false again after function done

        This prevent to traverse the vertex that exist on same tree where the vertex 1 exist
        So we can jump to vertex 4 to traverse because 4 and 5 on another tree
    */
    bool isCycleGraph(vector<vector<int>>& adjMat, vector<bool>& isVisited, vector<bool>& curStack, int idx){
        if(isVisited[idx]==false){
            curStack[idx]=true;
            isVisited[idx]=true;

            for(int i=0; i<adjMat[idx].size(); i++)
            {
                int indexTraverse = adjMat[idx][i];
                if(!isVisited[indexTraverse] && isCycleGraph(adjMat, isVisited, curStack, indexTraverse)) return true;
                if(curStack[indexTraverse]) return true;
            }
        }
        
        // remove current index from traverse
        curStack[idx]=false;
        return false;
    }

    /*
        Make adjacent matrix from prerequisites array
        Then traverse for every vertex to get cycle detection
    */

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjMat(numCourses);
        vector<bool> isVisited(numCourses, false);
        vector<bool> curStack(numCourses, false);
        bool isCycle = false;

        // Convert prerequisites to be a adjacent matrix
        for(int i=0; i<prerequisites.size(); i++)
        {
            adjMat[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        // Call cycle detection function (isCycleGraph) for every tree
        for(int i=0; i<numCourses; i++)
        {
            if(!isVisited[i] && isCycleGraph(adjMat, isVisited, curStack, i)){
                isCycle = true;
                break;
            }
        }
        return !isCycle;
    }
};