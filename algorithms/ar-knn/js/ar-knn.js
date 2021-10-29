/** 
 * @class Point
 * Class created to describe each point.
*/
class Point {
    constructor(x, y, group, distance) {
        this.x = x; // x-coordinate of point
        this.y = y; // y-coordinate of point
        this.group = group; // group to which the point belongs
        this.distance = distance; // distance of the point from the test point
    }
};

/**
 * @function distanceCompare 
 * Comparator function to sort points in the increasing order of distance 
 * from the test point.
 * @param {*} a Point instance
 * @param {*} b Point instance
 * @returns boolean value used while sorting. 
 */
function distanceCompare(a, b) {
    return a.distance < b.distance ? -1 : 1;
}

/**
 * @function classifyPointUsingKNN
 * This function finds classification of point testPoint using
 * k-nearest neighbour algorithm. It assumes only two
 * groups and returns 0 if testPoint belongs to group 0, else
 * 1 (belongs to group 1).
 * @param {*} inputPointsArray Array of Point instances
 * @param {*} pointsTotal Total no. of points
 * @param {*} k Value of parameter k
 * @param {*} testPoint Point instance whose group has to be classified
 * @returns The group to which the testPoint belongs by applying KNN algorithm
 */
function classifyPointUsingKNN(inputPointsArray, pointsTotal, k, testPoint) {
    let pointsArray = inputPointsArray;

    // Fill distances of all points from testPoint
    for (let i = 0; i < pointsTotal; i++) {
        pointsArray[i].distance =
            Math.sqrt((pointsArray[i].x - testPoint.x) * (pointsArray[i].x - testPoint.x) +
                (pointsArray[i].y - testPoint.y) * (pointsArray[i].y - testPoint.y));
    }

    // Sort the Points by distance from testPoint
    pointsArray.sort(distanceCompare);

    // Now consider the first k elements and only
    // two groups
    let freq0 = 0;     // Frequency of group 0
    let freq1 = 0;     // Frequency of group 1
    for (let i = 0; i < k; i++) {
        if (pointsArray[i].group == 0)
            freq0++;
        else if (pointsArray[i].group == 1)
            freq1++;
    }
    
    return (freq0 > freq1 ? 0 : 1);
}

// driver code
// array of points
let arr = [];

// inserting points into arr one by one
// setting initial distance as -1.
arr.push(new Point(1, 12, 0, -1));
arr.push(new Point(2, 5, 0, -1));
arr.push(new Point(5, 3, 1, -1));
arr.push(new Point(3, 2, 1, -1));
arr.push(new Point(3, 6, 0, -1));
arr.push(new Point(1.5, 9, 1, -1));
arr.push(new Point(7, 2, 1, -1));
arr.push(new Point(6, 1, 1, -1));
arr.push(new Point(3.8, 3, 1, -1));
arr.push(new Point(3, 10, 0, -1));
arr.push(new Point(5.6, 4, 1, -1));
arr.push(new Point(4, 2, 1, -1));
arr.push(new Point(3.5, 8, 0, -1));
arr.push(new Point(2, 11, 0, -1));
arr.push(new Point(2, 5, 1, -1));
arr.push(new Point(2, 9, 0, -1));
arr.push(new Point(1, 7, 0, -1));

// Testing point
let p = new Point(2.5, 7, -1, -1);

// Parameter k used to decide group of the testing point
let k = 3;
console.log("KNN Algorithm Implementation:");
console.log("Group assigned to test point: " + classifyPointUsingKNN(arr, arr.length, k, p));