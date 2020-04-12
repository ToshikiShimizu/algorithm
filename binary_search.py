import bisect
import unittest

def meguru_bisect(ng, ok, func):
    while (abs(ok - ng) > 1):
        mid = (ok + ng) // 2
        if func(mid):
            ok = mid
        else:
            ng = mid
    return ok

def bisect_left(a, x):
    def func(i):
        return x <= a[i]
    return meguru_bisect(-1, len(a), func)

def bisect_right(a, x):
    def func(i):
        return x < a[i]
    return meguru_bisect(-1, len(a), func)

class TestBisect(unittest.TestCase):
    def test_bisect(self):
        test_patterns = [
            ([2,3,4,4,5,6], 6),
            ([], 6),
            ([3,3], 0),
            ([3,3], 6),
        ]
        for a, x in test_patterns:
            with self.subTest(a=a, x=x):
                self.assertEqual(bisect_left(a, x), bisect.bisect_left(a, x))
            with self.subTest(a=a, x=x):
                self.assertEqual(bisect_right(a, x), bisect.bisect_right(a, x))


if __name__=='__main__':
    a = [2,3,4,4,5,6]
    x = 6
    print (bisect_left(a, x))
    print (bisect.bisect_left(a, x))
    print (bisect_right(a, x))
    print (bisect.bisect_right(a, x))
