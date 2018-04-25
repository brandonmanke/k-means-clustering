# K-Means Clustering Algorithm

> This is a basic implementation of the [K-Means Clustering Algorithm](https://en.wikipedia.org/wiki/K-means_clustering) written in C++.

I was inspired to implement this algorithm due to a couple of reasons. The main one being [this](https://www.youtube.com/watch?v=9991JlKnFmk) video by [Siraj Raval](https://twitter.com/sirajraval). The second reason being that I am interested in understanding the fundamentals of machine learning.

## K-Means What?

K-Means Clustering is considered an [Unsupervised learning algorithm](https://en.wikipedia.org/wiki/Unsupervised_learning). More specifically it is a classification/clustering algorithm. 

[TODO]

## Building

Via Docker:
```bash
# To build the image
docker build -t k-means-clustering .

# To build and run the program
docker run -it --rm k-means-clustering
```

Via your own compiler:
(This may or may not work depending on your compiler)
```bash
make && ./bin/out
```

## How it works?

Place k random centroid points on the graph

Repeat the following until specified limit or convergence:

For all points/vectors v in the Matrix:
Calculate the distance between each centroid c and v
Take the minimum distance to find the closest centroid
Assign that data point/vector to that cluster that the centroid c represents.

For all clusters:
Calculate the average/mean of all the points
Assign those averages as the new centroids for each cluster

(You can also stop when the clusters stop changing)

[TODO]

### Psuedocode

Here is some "Psuedocode"/JavaScript I wrote that describes (roughly) how I implemented this algorithm:

```JS
function kMeansClustering(k, limit) {
    let centroids = randomCentroids(k)
    let clusters = [] // groups of length k

    // cluster points
    clusterPoints(centroids)

    // average clusters for new centroids
    centroids = averageClusters(clusters, centroids)

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

## Resources

- https://github.com/llSourcell/k_means_clustering
