
# Maths/Calculation proofs and explanations

## 2D Matrix Rotation

To rotate a vector by angle θ (around the origin):

x′= xcosθ − ysinθ
y′ = xsinθ + ycosθ

matrix form:

[x′y′​]=[cosθsinθ​−sinθcosθ​][xy​]

* Note that a Rotation:
	* preserves vector len
	* changes direction
	* is linear
	* is trigonometry packed into a matrix

To rotate a vector by angle θ (around a chosen point [cx, cy]):

* translate to origin
* rotate
* translate back

Pseudo:

	p -= center
	rotate(p)
	p += center