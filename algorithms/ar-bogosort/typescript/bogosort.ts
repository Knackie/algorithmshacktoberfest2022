function bogoSort(list: number[]): number[] {
    let result = [...list]
    while (!isSorted(result)) {
        scramble(result)
    }
    return result
}

function isSorted(list: number[]): boolean {
    for (let i = 1; i < list.length; i++) {
        if (!(list[i] >= list[i - 1])) {
            return false
        }
    }
    return true
}

function scramble(list: number[]): void {
    for (let i = list.length - 1; i > 0; i--) {
        let newIndex = Math.floor(Math.random() * (i))
        let aux = list[i]
        list[i] = list[newIndex]
        list[newIndex] = aux
    }
}

const list: number[] = [3, 5, 6, 2, 5]

const sortedList: number[] = bogoSort(list)

console.log({
    list,
    sortedList
})