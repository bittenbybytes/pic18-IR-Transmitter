thickness_top = 3;
thickness_stem = thickness_top;
facet = 0;


drill = thickness_top + 2;
depth_cutout = 3;
coutout_h = depth_cutout+1;

translate([0,0,-(thickness_top+1)])
{
    union(){
        translate([-20,0,0])
        {
            cube([40,35,thickness_stem]);
        }

        translate([-20 +20,45,0])
        {
            rotate([0,0,90])
            {
                cylinder(thickness_top,50-facet,50,$fn=3);
            }
        }

        translate([-20 +20,45+30,0])
        {
            rotate([0,0,90])
            {
                cylinder(thickness_top,40,40-facet,$fn=3);
            }
        }

        translate([-20 +20,45+30+25,0])
        {
            rotate([0,0,90])
            {
                cylinder(thickness_top,30,30-facet,$fn=3);
            }
        }
    }
}