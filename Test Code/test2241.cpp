int maxElementsSumLessThanX(int N, int M, int X, int A[], int B[]) {
    sort(A, A + N, greater<int>()); // Sort array A in descending order
    sort(B, B + M, greater<int>()); // Sort array B in descending order
    
    int maxElements = 0;
    int sum = 0;
    int i = 0, j = 0;
    
    while (i < N && j < M) {
        if (A[i] + B[j] <= X) {
            sum += A[i] + B[j];
            i++;
            j++;
            maxElements += 2;
        } else if (A[i] <= X) {
            sum += A[i];
            i++;
            maxElements++;
        } else if (B[j] <= X) {
            sum += B[j];
            j++;
            maxElements++;
        } else {
            break;
        }
        
        if (sum > X) {
            maxElements--;
            break;
        }
    }
    
    while (i < N && A[i] <= X) {
        sum += A[i];
        i++;
        maxElements++;
        if (sum > X) {
            maxElements--;
            break;
        }
    }
    
    while (j < M && B[j] <= X) {
        sum += B[j];
        j++;
        maxElements++;
        if (sum > X) {
            maxElements--;
            break;
        }
    }
    
    return maxElements;
}
