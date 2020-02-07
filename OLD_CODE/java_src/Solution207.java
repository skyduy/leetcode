import java.util.ArrayList;
import java.util.Stack;

/**
 * @author Jun
 * 邻接矩阵，邻接表；DFS，TOPO Sort
 */
class Solution207 {
    private static final int PERMANENT_MARK = 1;
    private static final int TEMPORARY_MARK = 2;

    private boolean dfs(ArrayList<ArrayList<Integer>> graphAdj, int rootNode, int[] mark) {
        if (mark[rootNode] == PERMANENT_MARK){
            return true;
        } else if (mark[rootNode] == TEMPORARY_MARK){
            return false;
        } else {
            mark[rootNode] = TEMPORARY_MARK;
            for(int node: graphAdj.get(rootNode)){
                if(!dfs(graphAdj, node, mark)) {
                    return false;
                }
            }
            mark[rootNode] = PERMANENT_MARK;
            return true;
        }
    }

    /**
     * DFS, 邻接表
     */
    boolean canFinishV1(int numCourses, int[][] prerequisites) {
        // 构造邻接表
        ArrayList<ArrayList<Integer>> graphAdj = new ArrayList<>(numCourses);
        for (int i = 0; i < numCourses; i++) {
            graphAdj.add(new ArrayList<>());
        }
        for (int[] prerequisite : prerequisites) {
            graphAdj.get(prerequisite[0]).add(prerequisite[1]);
        }
        int[] mark = new int[numCourses];

        // 利用dfs方式判断
        for (int i = 0; i < numCourses; i++) {
            if(!dfs(graphAdj, i, mark)){
                return false;
            }
        }
        return true;
    }

    /**
     * BFS，邻接矩阵
     */
    boolean canFinishV0(int numCourses, int[][] prerequisites) {
        // 构造邻接矩阵
        boolean[][] graphMatrix = new boolean[numCourses][numCourses];
        int[] inDegree = new int[numCourses];
        for (int[] prerequisite : prerequisites) {
            inDegree[prerequisite[1]]++;
            graphMatrix[prerequisite[0]][prerequisite[1]] = true;
        }

        // 利用BFS方式
        int count = 0;
        Stack<Integer> noIn = new Stack<>();
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                noIn.push(i);
            }
        }
        while (!noIn.empty()) {
            count++;
            int from = noIn.pop();
            for (int to = 0; to < numCourses; to++) {
                if (graphMatrix[from][to]) {
                    inDegree[to]--;
                    if (inDegree[to] == 0) {
                        noIn.push(to);
                    }
                }
            }
        }
        return count == numCourses;
    }
}
