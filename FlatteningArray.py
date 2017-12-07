
def arrayFlatten(toBeFlattened):
	if toBeFlattened == []:
		return toBeFlattened
	if isinstance(toBeFlattened[0], list):
		return arrayFlatten(toBeFlattened[0]) + arrayFlatten(toBeFlattened[1:])
	return toBeFlattened[:1] + arrayFlatten(toBeFlattened[1:])

toBeFlattened = ["things", ["thing2", "thing3"], [["thing4","thing5"], ["thing6", "thing7"]]]
toBeFlattened = flatten(toBeFlattened)
print toBeFlattened
