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


def find_radius_v4(points, center):
    """ Also gives 89.95 :( """
    ws = [point[2] for point in points]
    ds = [dist(point[:2], center) for point in points]
    large = max(ds)
    small = min(ds)

    sum_wi_x_di = sum([di * wi for di, wi in zip(ds, ws)])
    sum_wi_x_di_square = sum([di * di * wi for di, wi in zip(ds, ws)])
    sum_wi = sum(ws)

    ans = None

    for i in range(1000):
        cand_r = 0 + i * (large - small) / 1000
        print(cand_r)
        cand_w = sum_wi_x_di_square + (cand_r * cand_r) * sum_wi - 2 * cand_r * sum_wi_x_di
        if ans is None or ans[1] > cand_w:
            ans = (cand_r, cand_w)

    return ans[0]


if __name__ == '__main__':
    n = int(input().strip())
    points = [0] * n
    for i in range(n):
        points[i] = list(map(int, input().strip().split()))
    center = weighted_centroid(points)
    radius = find_radius_v4(points, center)
    print(*center, radius)
