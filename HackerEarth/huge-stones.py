from math import sqrt


def weighted_centroid(points):
    x = y = w = 0
    for a, b, c in points:
        x += c * a
        y += c * b
        w += c
    x /= w
    y /= w
    return (x, y)


def dist(p1, p2):
    return sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)


def find_radius(points, center):
    """ Gives 80 Points """
    r = 0
    for point in points:
        dis = dist(point[:2], center)
        if(dis > r):
            r = dis
    return r / 2


def work(points, center, radius):
    rt = 0
    for point in points:
        dis = dist(point[:2], center)
        rt += abs(dis - radius) * point[2]
    return rt


def find_radius_v2(points, center):
    """ Median Distance as radius: Gives 90.85 Points """
    distances = [dist(point[:2], center) for point in points]
    distances.sort()
    return distances[len(distances) // 2]


def find_radius_v3(points, center):
    """ Mean Distance as radius: Gives 89.95 Points"""
    distances = [dist(point[:2], center) for point in points]
    return sum(distances) / len(distances)


if __name__ == '__main__':
    n = int(input().strip())
    points = [0] * n
    for i in range(n):
        points[i] = list(map(int, input().strip().split()))
    center = weighted_centroid(points)
    radius = find_radius_v2(points, center)
    print(*center, radius)
