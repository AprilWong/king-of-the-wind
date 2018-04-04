# king-of-the-wind

king-of-the-wind is a wind power image generator. It generates 2D wind power image with wind power data at some coordinates.
The generated wind power image will be used for computation in wind power system (there is a preliminary solution).

## Wind model

- direction
- intensity

## Input

- atmospheric pressure at some coordinates
    - the pressure is used to calculate wind direction

- regional wind intensity
    - the regional wind intensity is modified
    - the intensity affects the density of isobaric line in the graph of atomospheric pressure
    - regional wind intensity can be output directly
    
## Output

- atmospheric pressure changes
    - wind direction（vector2）
- regional wind intensity

## core features
- input the atmospheric pressure and basic atmospheric pressure at two coordinates, and output the whole graph of atmospheric pressure
- compute wind direction with the atmospheric pressure
- visualize wind direction and wind intensity

## Computation of atmospheric pressure at any point

### computation

``` U' = U + Σ ((U<sub>i</sub> - U) / d) ```

### theoretical basis

- The pressure change is determined by the temperature. 
- The ideal gas isobaric surface and the isothermal surface are the same plane.
- The thermal conductivity is inversely proportional to the distance, and is proportional to the temperature difference.
- If the air is regarded as the ideal gas, the pressure at any point satisfies ``` U' = U + Σ ((U<sub>i</sub> - U) / d) ```.

## computation of wind power
- Theoretically, the wind power is related to the isobaric line in the graph of atmospheric pressure.
- 但是为了美术能更加直观地进行贴图的创建，因此我们只从气压图中得到风的方向，而由美术另外指定一张风的强度贴图。

## storage of computation result
- The result is stored in 2D image.
- A channel stores the wind power.
- RG channel stores the vector direction of the wind at certain point
    
## References
- [https://www.geogebra.org/material/show/id/3051](https://www.geogebra.org/material/show/id/3051)
- [http://www.falstad.com/vector/](http://www.falstad.com/vector/)
- [https://help.scilab.org/champ](https://help.scilab.org/champ)
- [http://www.sci.utah.edu/~cscheid/scivis_fall07/2d_vector_vis.pdf](http://www.sci.utah.edu/~cscheid/scivis_fall07/2d_vector_vis.pdf)
- [https://www.cg.inf.ethz.ch/teaching/scivis_common/Literature/HelmanHesselink91.pdf](http://www.sci.utah.edu/~cscheid/scivis_fall07/2d_vector_vis.pdf)
- [http://repository.cmu.edu/cgi/viewcontent.cgi?article=1394&context=psychology](http://repository.cmu.edu/cgi/viewcontent.cgi?article=1394&context=psychology)
- [http://www-users.cs.umn.edu/~interran/francesca06.pdf](http://www-users.cs.umn.edu/~interran/francesca06.pdf)
- [http://www3.nd.edu/~cwang11/research/vis13-tutorial-weiskopf.pdf](http://www3.nd.edu/~cwang11/research/vis13-tutorial-weiskopf.pdf)

## Referenced example 
- [https://www.windyty.com](https://www.windyty.com)

## Revisions
2016.7.12 first commit

----

latest update: 2016.7.13

- Added the computation method of the atmospheric pressure and the theoretical basis.
