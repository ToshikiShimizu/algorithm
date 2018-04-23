#coding:utf-8
"""
LightsOutを解くプログラム
標準ライブラリを用いて実装した
（デバッグ時のみnumpyを使用）
"""
import random
import itertools
import copy


def print_np(array):#デバッグ用
    import numpy as np
    print (np.array(array))

def np_dot(target,A):#デバッグ用
    import numpy as np
    temp1 = np.array(target)[:,-1]
    print (temp1)
    temp2 = np.array(A)[:-1]
    print (temp2)
    temp3 = np.array(A)[-1]
    print ((temp3 + temp2.dot(temp1))%2)


def transpose(array):#転置
    return list((map(list,zip(*array))))

def add(a,b):#二つのリストの論理和を返す
    return  [ (i+j)%2 for (i,j) in  zip(a,b) ]

def generate_problem():#問題の作成
    problem = []
    for m in range(M):
        row = ""
        for n in range(N):
            if random.random() < theta:
                row += "o"#ON
            else:
                row += "-"#OFF
        problem.append(row)
    return problem

def convert_binary(problem):#問題をバイナリ表現に変換
    vec = []
    for row in problem:
        for state in row:
            if state == "o":
                vec.append(1)
            else:
                vec.append(0)
    return vec

def main():
    A = []
    problem = generate_problem()
    # problem = ["oo-","o--","---"]
    #problem = ["o-","-o"]
    #problem = ["ooo-","o---","----","----"]
    print (problem)
    b = convert_binary(problem)#問題をバイナリ表現に変換
    print (b)
    for i in range(M*N):
        v = [0 for _ in range(M*N)]
        v[i] = 1#選択したマス
        if i-N >= 0:
            v[i-N] = 1#上
        if i+N < M*N:
            v[i+N] = 1#下
        if (i-1)%N < i%N:
            v[i-1] = 1#左
        if i%N < (i+1)%N:
            v[i+1] = 1#右

        A.append(v)
    A.append(b)#Aはもともと対称行列
    target = transpose(A)
    for j in range(M*N):#掃き出しに用いる軸の番号
        if target[j][j]==1:#対角成分を最後まで1に変換できた場合（ただ一つの解が存在）、関数の最後でリターン
            pass
        else:#もしこの段階で[j][j]が0である場合、[j][j]=1となるように行を入れ替える
            for i_ in range(j+1,M*N):
                if target[i_][j]==1:
                    temp = target[i_]
                    target[i_] = target[j]
                    target[j] = temp
                    break#入れ替えに成功したらbreak
            else:#入れ替えに失敗した場合は、不定または不能である
                if sum(map(sum, target[j:])) == 0:#不定
                    n_sol = []#操作回数のリスト
                    ls = list(itertools.product([0,1],repeat=M*N-j))
                    for param in ls:
                        ans = transpose(copy.deepcopy(target))#最後の列(行)を変更するのでdeepcopyを取る
                        for k,flag in enumerate(param):
                            if flag == 1:
                                ans[-1] = add(ans[-1],ans[j+k])#フラグの箇所だけ切り替えを行う
                        n_sol.append(sum(ans[-1])+sum(param))
                    return min(n_sol)
                else:#不能
                    return -1

        for i in range(M*N):
            if i!=j:
                if target[i][j] == 1:#掃き出す
                    target[i] = add(target[i],target[j])#論理代数なので加えればよい
    return sum(transpose(target)[-1])#対角成分を最後まで1に変換できた場合（ただ一つの解が存在）、関数の最後でリターン

if __name__=="__main__":
    random.seed()#4*4ではseed=7で不定となる
    theta = 0.5#問題作成用の閾値
    M = 10#行数
    N = 10#列数
    r = main()
    print (r)
