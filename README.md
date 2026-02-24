# c_codes 🧮

> 🇺🇸 [English](#english) | 🇲🇽 [Español](#español)

---

## English

Collection of C programs developed for numerical applications and physics-math simulations.

---

### Compilation

To compile any file:

```bash
gcc -Wall -Wextra -std=c99 -o program_name file.c -lm
```

> The `-lm` flag is required for programs that use math functions (`math.h`).  
> `-Wall -Wextra` enables all compiler warning messages.

**Example:**
```bash
gcc -Wall -Wextra -std=c99 -o fib fib.c
./fib
```

---

### Programs

#### `fib.c` — Fibonacci Series
Computes the first `n` terms of the Fibonacci sequence:

$$F(0) = 0,\quad F(1) = 1,\quad F(n) = F(n-1) + F(n-2)$$

- **Input:** number of terms `n`
- **Output:** printed to screen and saved to `Fib.dat`

```bash
gcc -Wall -std=c99 -o fib fib.c && ./fib
```

---

#### `arm.c` — Harmonic Series
Computes the partial sum of the harmonic series up to `n` terms:

$$H_n = \sum_{i=1}^{n} \frac{1}{i} = 1 + \frac{1}{2} + \frac{1}{3} + \cdots + \frac{1}{n}$$

- **Input:** number of terms `n`
- **Output:** each cumulative term printed and saved to `harm.dat`

```bash
gcc -Wall -std=c99 -o arm arm.c && ./arm
```

---

#### `quad.c` — Inverse Squares Series
Computes the sum of inverse squares up to `n` terms.  
As it converges it approaches the classic result: $\sum_{i=1}^{\infty} \frac{1}{i^2} = \frac{\pi^2}{6} \approx 1.6449$

$$Q_n = \sum_{i=1}^{n} \frac{1}{i^2}$$

- **Input:** number of terms `n`
- **Output:** printed to screen and saved to `quad.dat`

```bash
gcc -Wall -std=c99 -o quad quad.c && ./quad
```

---

#### `moneda.c` — Coin Flip Simulation
Simulates flipping a coin (heads or tails) using C's pseudorandom number generator.

- **Input:** number of flips per experiment and number of experiment repetitions
- **Output:** results on screen; `aguilas.dat` (heads) and `sellos.dat` (tails) for plotting distributions

```bash
gcc -Wall -std=c99 -o moneda moneda.c && ./moneda
```

---

#### `proyectil1.c` — Projectile Motion (from ground level)
Simulates the trajectory of a projectile launched from the ground under gravity.

$$x(t) = v_0 \cos\theta \cdot t \qquad y(t) = v_0 \sin\theta \cdot t - \frac{1}{2}g t^2$$

- **Input:** initial velocity $v_0$ [m/s] and launch angle $\theta$ [degrees]
- **Output:** $(x, y)$ coordinates on screen and in `coordproy1.dat`, flight time, and max height

```bash
gcc -Wall -std=c99 -o proyectil1 proyectil1.c -lm && ./proyectil1
```

---

#### `proyectil2.c` — Projectile Motion (from an initial height)
Extends `proyectil1.c` with an initial height $h_0 = 150$ m. Initial conditions are hardcoded ($v_0 = 50$ m/s, $\theta = 45°$).

$$y(t) = h_0 + v_0 \sin\theta \cdot t - \frac{1}{2}g t^2$$

- **Output:** $(x, y)$ coordinates on screen and in `coordproy2.dat`

```bash
gcc -Wall -std=c99 -o proyectil2 proyectil2.c -lm && ./proyectil2
```

---

#### `triangulo.c` — Triangle Area (Heron's Formula)
Computes the area of a triangle given its three sides, first verifying the triangle inequality.

$$p = \frac{a+b+c}{2} \qquad A = \sqrt{p(p-a)(p-b)(p-c)}$$

- **Input:** sides $a$, $b$, $c$
- **Output:** area of the triangle or an error message if the sides are invalid

```bash
gcc -Wall -std=c99 -o triangulo triangulo.c -lm && ./triangulo
```

---

#### `vectores1.c` — 3D Vector Addition
Adds two 3-dimensional integer vectors entered by the user.

$$\vec{v_3} = \vec{v_1} + \vec{v_2}$$

- **Input:** integer components of `vector1` and `vector2`
- **Output:** components of the resulting `vector3`

```bash
gcc -Wall -std=c99 -o vectores1 vectores1.c && ./vectores1
```

---

#### `LV.c` — Lotka-Volterra Model (Predator-Prey)
Implements the approximate analytical solution of the **Lotka-Volterra** system, modeling predator-prey population dynamics:

$$\frac{dH}{dt} = \alpha H - \beta H P \qquad \frac{dP}{dt} = \delta H P - \gamma P$$

Default parameters: $\alpha=1.1$, $\beta=0.9$, $\gamma=1.0$, $\delta=2.0$, with initial conditions $H_0=0.9$, $P_0=1.8$. Also computes the conserved quantity $V(H,P)$.

- **Output:** trajectories $(H, P, V)$ saved to `LV2.dat` (ready to plot with gnuplot)

```bash
gcc -Wall -std=c99 -o LV LV.c -lm && ./LV
```

---

### Output files

| Program | Output file |
|---|---|
| `fib.c` | `Fib.dat` |
| `arm.c` | `harm.dat` |
| `quad.c` | `quad.dat` |
| `moneda.c` | `aguilas.dat`, `sellos.dat` |
| `proyectil1.c` | `coordproy1.dat` |
| `proyectil2.c` | `coordproy2.dat` |
| `LV.c` | `LV2.dat` |

---

## Español

Colección de programas en C desarrollados para aplicaciones numéricas y simulaciones físico-matemáticas.

---

## Compilación

Para compilar cualquier archivo:

```bash
gcc -Wall -Wextra -std=c99 -o nombre_programa archivo.c -lm
```

> La bandera `-lm` es necesaria para los programas que usan funciones matemáticas (`math.h`).  
> `-Wall -Wextra` activa todos los mensajes de advertencia del compilador.

**Ejemplo:**
```bash
gcc -Wall -Wextra -std=c99 -o fib fib.c
./fib
```

---

## Programas

### `fib.c` — Serie de Fibonacci
Calcula los primeros `n` términos de la sucesión de Fibonacci:

$$F(0) = 0,\quad F(1) = 1,\quad F(n) = F(n-1) + F(n-2)$$

- **Entrada:** número de términos `n`
- **Salida:** imprime en pantalla y guarda en `Fib.dat`

```bash
gcc -Wall -std=c99 -o fib fib.c && ./fib
```

---

### `arm.c` — Serie Armónica
Calcula la suma parcial de la serie armónica hasta `n` términos:

$$H_n = \sum_{i=1}^{n} \frac{1}{i} = 1 + \frac{1}{2} + \frac{1}{3} + \cdots + \frac{1}{n}$$

- **Entrada:** número de términos `n`
- **Salida:** imprime cada término acumulado en pantalla y guarda en `harm.dat`

```bash
gcc -Wall -std=c99 -o arm arm.c && ./arm
```

---

### `quad.c` — Serie de Cuadrados Inversos
Calcula la suma de los inversos de los cuadrados hasta `n` términos.  
Al converger tiende al resultado clásico: $\sum_{i=1}^{\infty} \frac{1}{i^2} = \frac{\pi^2}{6} \approx 1.6449$

$$Q_n = \sum_{i=1}^{n} \frac{1}{i^2}$$

- **Entrada:** número de términos `n`
- **Salida:** imprime en pantalla y guarda en `quad.dat`

```bash
gcc -Wall -std=c99 -o quad quad.c && ./quad
```

---

### `moneda.c` — Simulación de Lanzamiento de Moneda
Simula el lanzamiento de una moneda (águila o sello) usando el generador de números pseudoaleatorios de C.

- **Entrada:** número de lanzamientos por experimento y número de repeticiones del experimento
- **Salida:** resultados por pantalla y archivos `aguilas.dat` / `sellos.dat` (útil para graficar distribuciones)

```bash
gcc -Wall -std=c99 -o moneda moneda.c && ./moneda
```

---

### `proyectil1.c` — Tiro Parabólico (desde el suelo)
Simula la trayectoria de un proyectil lanzado desde el suelo bajo la acción de la gravedad.

$$x(t) = v_0 \cos\theta \cdot t \qquad y(t) = v_0 \sin\theta \cdot t - \frac{1}{2}g t^2$$

- **Entrada:** velocidad inicial $v_0$ [m/s] y ángulo de lanzamiento $\theta$ [grados]
- **Salida:** coordenadas $(x, y)$ en pantalla y en `coordproy1.dat`, tiempo de vuelo y altura máxima

```bash
gcc -Wall -std=c99 -o proyectil1 proyectil1.c -lm && ./proyectil1
```

---

### `proyectil2.c` — Tiro Parabólico (desde una altura inicial)
Extiende `proyectil1.c` con una altura inicial $h_0 = 150$ m. Las condiciones iniciales están fijas en el código ($v_0 = 50$ m/s, $\theta = 45°$).

$$y(t) = h_0 + v_0 \sin\theta \cdot t - \frac{1}{2}g t^2$$

- **Salida:** coordenadas $(x, y)$ en pantalla y en `coordproy2.dat`

```bash
gcc -Wall -std=c99 -o proyectil2 proyectil2.c -lm && ./proyectil2
```

---

### `triangulo.c` — Área de un Triángulo (Fórmula de Herón)
Calcula el área de un triángulo dados sus tres lados, verificando primero que los lados formen un triángulo válido mediante la **desigualdad triangular**.

$$p = \frac{a+b+c}{2} \qquad A = \sqrt{p(p-a)(p-b)(p-c)}$$

- **Entrada:** lados $a$, $b$, $c$
- **Salida:** área del triángulo o mensaje de error si los lados no son válidos

```bash
gcc -Wall -std=c99 -o triangulo triangulo.c -lm && ./triangulo
```

---

### `vectores1.c` — Suma de Vectores 3D
Suma dos vectores de dimensión 3 ingresados por el usuario.

$$\vec{v_3} = \vec{v_1} + \vec{v_2}$$

- **Entrada:** componentes enteras de `vector1` y `vector2`
- **Salida:** componentes del vector resultante `vector3`

```bash
gcc -Wall -std=c99 -o vectores1 vectores1.c && ./vectores1
```

---

### `LV.c` — Modelo de Lotka-Volterra (Depredador-Presa)
Implementa la solución analítica aproximada del sistema de ecuaciones de **Lotka-Volterra**, que modela la dinámica de poblaciones depredador-presa:

$$\frac{dH}{dt} = \alpha H - \beta H P \qquad \frac{dP}{dt} = \delta H P - \gamma P$$

Usando los parámetros por defecto: $\alpha=1.1$, $\beta=0.9$, $\gamma=1.0$, $\delta=2.0$,  
y condiciones iniciales $H_0=0.9$, $P_0=1.8$. También calcula la integral de movimiento $V(H,P)$.

- **Salida:** trayectorias $(H, P, V)$ guardadas en `LV2.dat` (apto para graficar con gnuplot)

```bash
gcc -Wall -std=c99 -o LV LV.c -lm && ./LV
```

---

## Archivos de salida generados

| Programa | Archivo de salida |
|---|---|
| `fib.c` | `Fib.dat` |
| `arm.c` | `harm.dat` |
| `quad.c` | `quad.dat` |
| `moneda.c` | `aguilas.dat`, `sellos.dat` |
| `proyectil1.c` | `coordproy1.dat` |
| `proyectil2.c` | `coordproy2.dat` |
| `LV.c` | `LV2.dat` |