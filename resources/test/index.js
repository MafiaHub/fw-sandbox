sdk.on('resourceLoaded', () => {
    console.log('resource loaded');

    const vec = new sdk.Vector3(0,1)
    console.log(vec)
    const q1 = new sdk.Quaternion.fromEuler(0,1)
    const q2 = new sdk.Quaternion.fromAxisAngle(90, 1, 0, 0)
    console.log(q1)
    console.log(q1.toArray())
    console.log(q2.rotateVec3(new sdk.Vector3(0,0,1)))
});

console.log('hello from the other side');
