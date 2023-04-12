#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int A[500][500];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int Spread[5][5] = {
    {0, 0, 2, 0, 0},
    {0, 10, 7, 1, 0},
    {5, 0, 0, 0, 0},
    {0, 10, 7, 1, 0},
    {0, 0, 2, 0, 0}};
int tmp[5][5];
int tmp2[5][5];
void sandSpread(int d)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            tmp2[i][j] = Spread[i][j];
        }
    }
    for (int k = 0; k < d; k++)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                tmp[i][j] = tmp2[j][4 - i];
            }
        }
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                tmp2[i][j] = tmp[i][j];
            }
        }
    }
}
int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            tmp2[i][j] = Spread[i][j];
        }
    }
    int answer = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }
    int total_move = N * N;
    int change_count = 0;
    int target_length = 1;
    int sx, sy;
    int tx, ty;
    sx = sy = N / 2;

    // first move is left
    int direc = 0;
    while (total_move > 0)
    {

        int move_count = 0;
        // move target_length
        while (move_count < target_length)
        {
            if(sx == 0 && sy == 0) break;
            // tonado's new location
            sx = sx + dx[direc];
            sy = sy + dy[direc];
            // The Sand in this area have to move
            int sandSum = A[sx][sy];
            A[sx][sy] = 0;
            int sumTmp = sandSum;
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    int sandportion = tmp2[i][j];

                    int sand_move_amount = (int)(((sandSum) / 100.0) * sandportion);
                    sumTmp -= sand_move_amount;
                    int realx = i + sx - 2;
                    int realy = j + sy - 2;
                    if (realx < 0 || realx >= N || realy < 0 || realy >= N)
                    {
                        answer += sand_move_amount;
                        continue;
                    }
                    A[realx][realy] += sand_move_amount;
                }
            }
            int nx = sx + dx[direc];
            int ny = sy + dy[direc];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N)
                A[nx][ny] += sumTmp;
            else
                answer += sumTmp;
            total_move--;
            move_count++;
        }
        if(sx == 0 && sy == 0) break;
        direc = (direc + 1) % 4;
        sandSpread(direc);
        // change direction
        change_count++;
        // if change_count is 2, reset to 0 and increase the target_length
        // target_length: 1,1,2,2,3,3,4,4,....
        if (change_count == 2)
        {
            change_count = 0;
            target_length++;
        }
    }
    cout << answer;
}