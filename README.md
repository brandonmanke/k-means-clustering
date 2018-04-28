# K-Means Clustering Algorithm

> This is a basic implementation of the [K-Means Clustering Algorithm](https://en.wikipedia.org/wiki/K-means_clustering) written in C++.

I was inspired to implement this algorithm due to a couple of reasons. The main one being [this](https://www.youtube.com/watch?v=9991JlKnFmk) video by [Siraj Raval](https://twitter.com/sirajraval). The second reason being that I am interested in understanding the fundamentals of machine learning.

## Table of Contents
- [Building](#building)
- [K-Means What?](#k-means-what)
- [How it Works?](#how-it-works)
- [Psuedocode](#psuedocode)
- [Example Output](#example-output)
- [Resources](#resources)

## Building

Via Docker:
```bash
# To build the image
make docker-build # OR docker build -t k-means-clustering .

# To build and run the program
make docker-run # OR docker run -it --rm k-means-clustering
```

Via your own compiler:
(This may or may not work depending on your compiler)
```bash
make && ./bin/out
```

## K-Means What?

K-Means Clustering is considered an [Unsupervised learning algorithm](https://en.wikipedia.org/wiki/Unsupervised_learning). More specifically it is a clustering algorithm that is able to classify n-dimensional vectors into k distinct groups. This algorithm in particular is considered an [NP-hard](https://en.wikipedia.org/wiki/NP-hardness) problem. This essentially means that it cannot be computed in polynomial time without the use of a theoretical non-deterministic computer. To prevent this, most algorithms end of using a heuristic approach which prioritize runtime over complete accuracy (limit iterations). Unsupervised learning, while ideal, is not nearly as accurate as [Supervised learning](https://en.wikipedia.org/wiki/Supervised_learning). However, since unsupervised algorithms don't need to rely on labeled data, this makes them *generally* easier to implement. 

## How it works?

Place k random centroid points on the graph.

Repeat the following until specified limit or convergence:

For all points/vectors v in the Matrix:
Calculate the distance between each centroid c and v.
Take the minimum distance to find the closest centroid.
Assign that data point/vector to that cluster that the centroid c represents.

For all clusters:
Calculate the average/mean of all the points.
Assign those averages as the new centroids for each cluster.

(You can also stop when the clusters stop changing)

## Psuedocode

Here is some "Psuedocode"/JavaScript I wrote that describes (roughly) how I implemented this algorithm:

```JS
function kMeansClustering(k, limit) {
    let centroids = randomCentroids(k)
    let clusters = [] // groups of length k

    let iteration = 0
    while (iteration < limit) {
        clusters = clusterPoints(centroids)
        centroids = averageClusters(clusters, centroids)
        iteration++
    }
    return clusters
}

function clusterPoints(centroids) {
    for (Point p in Matrix) {
        let min = Number.MAX_VALUE
        let index = -1
        for (Centroid c in centroids) {
            let distance = EuclideanDist(p, c)
            if (distance < min) {
                min = distance
                index = indesOf(c)
            }
        }
        clusters[index].add(p)
    }
}

function averageClusters(clusters, centroids) {
    for (Cluster c in clusters) {
        let sum = zero_vector
        for (Point p in c) {
            sum += p
        }
        let average = sum / c.length
        centroids[indexOf(c)] = average
    }
}

```

## Example Output

This is an example output after 8 iterations of training. We then classify a random point with the clustered data.

```
Iteration 8: 
Cluster 0: (Centroid = [ 439, 476, 685 ])
Point: 0 - [ 506, 620, 838 ]
Point: 1 - [ 415, 344, 542 ]
Point: 2 - [ 527, 308, 966 ]
Point: 3 - [ 493, 201, 883 ]
Point: 4 - [ 544, 945, 826 ]
Point: 5 - [ 925, 323, 577 ]
Point: 6 - [ 373, 457, 876 ]
Point: 7 - [ 303, 527, 500 ]
Point: 8 - [ 361, 773, 527 ]
Point: 9 - [ 328, 267, 729 ]
Point: 10 - [ 502, 953, 956 ]
Point: 11 - [ 466, 971, 670 ]

Cluster 1: (Centroid = [ 40, 71, 222 ])
Point: 0 - [ 21, 137, 284 ]
Point: 1 - [ 101, 77, 382 ]
Point: 2 - [ 140, 274, 7 ]

Cluster 2: (Centroid = [ 449, 56, 189 ])
Point: 0 - [ 674, 122, 436 ]
Point: 1 - [ 674, 46, 133 ]
Point: 2 - [ 551, 69, 379 ]

Cluster 3: (Centroid = [ 631, 538, 153 ])
Point: 0 - [ 935, 985, 211 ]
Point: 1 - [ 641, 816, 238 ]
Point: 2 - [ 483, 386, 108 ]
Point: 3 - [ 830, 520, 172 ]
Point: 4 - [ 757, 632, 190 ]
Point: 5 - [ 771, 430, 153 ]
Point: 6 - [ 860, 449, 303 ]

Cluster 4: (Centroid = [ 88, 520, 225 ])
Point: 0 - [ 63, 530, 347 ]
Point: 1 - [ 70, 623, 339 ]
Point: 2 - [ 212, 530, 394 ]
Point: 3 - [ 97, 919, 49 ]
Point: 4 - [ 18, 759, 140 ]

Classify p: [ 791, 248, 128 ]
Is closest to cluster: 3
```

## Resources

- https://github.com/llSourcell/k_means_clustering
- https://www.datascience.com/blog/k-means-clustering
- Some Wikipedia

## License 

All of the software in this repository is licensed under the [MIT License](LICENSE) unless otherwise specified by 3rd party library/language/etc.
