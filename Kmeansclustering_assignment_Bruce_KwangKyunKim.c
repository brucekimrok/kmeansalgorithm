#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 3 //a number of clusters

#define N 9 // a number of coordinates 

#define BIGNUM INFINITY

struct Point2D
{
	float x, y;
};
typedef struct Point2D Point2D;

void kMeansClustering(const Point2D p1[], Point2D m1[]);  

int main()
{
	int n;
	Point2D p[N] = { { 11.0, 15.0 }, { 4.0, 12.0 }, { 9.0, 4.0 }, { 6.0, 13.0 }, { 12.0, 14.0 }, { 8.0, 5.0 }, { 3.0, 14.0 }, { 14.0, 16.0 }, { 5.0, 4.0 } };
	Point2D m[K] = { { 10.0, 15.0 }, { 6.0, 13.0 }, { 3.0, 14.0 } };

	kMeansClustering(p, m);		

	for (n = 0; n < K; n++)
	{
		printf("\n(%f, %f) ", m[n].x, m[n].y);
	}

	return 0;
}


void kMeansClustering(const Point2D p1[], Point2D m1[])	
{
	Point2D c[K] = { {0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0} };
	int i, j, best_index = -1;
	float cur_distance[K];
	float closest_distance = BIGNUM;
	int cluster_assignment_index[N];

	int count[K];	
	int do_again;
	// find distance between centroids and plots, then assign plots to the closest centroid. 
	do
	{
		memset(count, 0, sizeof(int)*K);
		memset(c, 0, sizeof(Point2D)*K);
		for (i = 0; i < N; i++)
		{
			closest_distance = BIGNUM;	
			for (j = 0; j < K; j++)
			{

				cur_distance[j] = ((m1[j].x) - (p1[i].x)) * ((m1[j].x) - (p1[i].x)) + ((m1[j].y) - (p1[i].y)) * ((m1[j].y) - (p1[i].y));
				if (cur_distance[j] < closest_distance)
				{
					best_index = j;
					closest_distance = cur_distance[j];
				}
			}
			cluster_assignment_index[i] = best_index;

			c[best_index].x += (p1[i].x);  
			c[best_index].y += (p1[i].y);

			//find the size of dividend 
			count[best_index]++;

		}
		do_again = 0;
		for (j = 0; j < K; j++)
		{
			float x, y;.
			if (count[j]) {
				x = ((c[j].x) / count[j]);
				y = ((c[j].y) / count[j]);
				if (m1[j].x != x || m1[j].y != y) {
					m1[j].x = x;
					m1[j].y = y;
					do_again = 1;
				}
			}
		}
	} while (do_again);
}