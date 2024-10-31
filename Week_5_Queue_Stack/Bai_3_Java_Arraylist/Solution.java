package Week_5_Queue_Stack.Bai_3_Java_Arraylist;

import java.util.*;

public class Solution {
    ArrayList<ArrayList<Integer>> numberList;

    public Solution() {
        numberList = new ArrayList<>();
    }

    static class Pos {  
        public int row;
        public int col;
    };

    public void printOneAnswer(int row, int col) {
        if (row < 1 || numberList.size() < row) {
            System.out.println("ERROR!");
            return;
        }
        if (col < 1 || numberList.get(row - 1).size() < col) {
            System.out.println("ERROR!");
            return;
        }
        System.out.println(numberList.get(row - 1).get(col - 1));
    }

    public void printAllAnswer(int numQues, ArrayList<Pos> posQuesList) {
        for (int i = 0; i < numQues; i++) {
            printOneAnswer(posQuesList.get(i).row, posQuesList.get(i).col);
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        ArrayList<Solution.Pos> posQuesList = new ArrayList<>();
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int rowSize = sc.nextInt();
            if (rowSize < 1) {
                ArrayList<Integer> row = new ArrayList<>();
                solution.numberList.add(row);
                continue;
            }
            ArrayList<Integer> row = new ArrayList<>();
            for (int j = 0; j < rowSize; j++) {
                row.add(sc.nextInt());
            }
            solution.numberList.add(row);
        }
        
        int numQues = sc.nextInt();
        for (int i = 0; i < numQues; i++) {
            Solution.Pos posQ = new Solution.Pos();
            posQ.row = sc.nextInt();
            posQ.col = sc.nextInt();
            posQuesList.add(posQ);
        }
        solution.printAllAnswer(numQues, posQuesList);
        sc.close();
    }
}
