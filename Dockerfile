FROM gcc:7.3
COPY . /usr/src/k-means-clustering/
WORKDIR /usr/src/k-means-clustering/
RUN make
CMD ["./bin/out"]