const bubbleSort = (values: number[]) => {
    const n = values.length;
    const result = [...values];

    for (let i = 0; i < n - 1; i++) {
        for (let j = 0; j < n - 1; j++) {
            if (result[j] > result[j + 1]) {
                const temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }

    return result;
};

console.log(bubbleSort([23, 42, 4, 15, 8, 16]));

