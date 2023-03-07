import macros
type Lock*[T] = ref object
    data: T
    isLocked: bool

proc lock*[T](k: T): Lock[T]=
    result = Lock[T](data: k, isLocked: false)

macro sync[T](v: Lock[T], body: untyped): untyped =
    quote do:
        `v`.isLocked = true
        `body`
        `v`.isLocked = false
let x: Lock[int]=lock(5)
sync(x):
    echo x.data
