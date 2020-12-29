BOOST_AUTO_TEST_CASE(equatorial_coord_default_hour_angle_constructor)
{
    equatorial_coord<double,
                     HourAngle<double, bu::quantity<bu::si::plane_angle>>,
                     quantity<bud::plane_angle>>
                     e;


    //Create object of Right Ascension
    HourAngle<double, bu::quantity<bu::si::plane_angle>>
            ha(25.0 * bu::si::radian);

    //Check value
    BOOST_CHECK_CLOSE(ha.get_angle().value(), 25.0, 0.001);

    //Quantity stored as expected?
    BOOST_TEST((std::is_same<decltype(ha.get_angle()), bu::quantity<bu::si::plane_angle>>::value));

    //Check set_X_Declination
    e.set_X_Declination(ha, 39.0 * bud::degree);

    BOOST_CHECK_CLOSE(e.get_X().get_angle().value(), 25.0, 0.001);
    BOOST_CHECK_CLOSE(e.get_Declination().value(), 39.0, 0.001);

    BOOST_TEST((std::is_same<decltype(e.get_X().get_angle()), bu::quantity<bu::si::plane_angle>>::value));
    BOOST_TEST((std::is_same<decltype(e.get_Declination()), quantity<bud::plane_angle>>::value));
}

BOOST_AUTO_TEST_CASE(equatorial_coord_quantities_right_ascension_constructor)
{
    //Create object of Right Ascension
    RightAscension<double, bu::quantity<bu::si::plane_angle>>
            ra(25.0 * bu::si::radian);

    //Check values
    BOOST_CHECK_CLOSE(ra.get_angle().value(), 25.0, 0.001);

    //Quantity stored as expected?
    BOOST_TEST((std::is_same<decltype(ra.get_angle()), bu::quantity<bu::si::plane_angle>>::value));

    //Make Equatorial Coordinate Check
    auto e1 = make_equatorial_coord(ra, 6.0 * bud::degree);

    //Check values
    BOOST_CHECK_CLOSE(e1.get_X().get_angle().value(), 25.0, 0.001);
    BOOST_CHECK_CLOSE(e1.get_Declination().value(), 6.0, 0.001);

    //Quantity stored as expected?
    BOOST_TEST((std::is_same<decltype(e1.get_X().get_angle()), bu::quantity<bu::si::plane_angle>>::value));
    BOOST_TEST((std::is_same<decltype(e1.get_Declination()), quantity<bud::plane_angle>>::value));

    //Equatorial Coordinate constructor
    equatorial_coord<double, RightAscension<double, bu::quantity<bu::si::plane_angle>>, quantity<bud::plane_angle>>
            e2(ra, 9.0 * bud::degrees);

    //Check values
    BOOST_CHECK_CLOSE(e2.get_X().get_angle().value(), 25.0, 0.001);
    BOOST_CHECK_CLOSE(e2.get_Declination().value(), 9.0, 0.001);

    //Quantity stored as expected?
    BOOST_TEST((std::is_same<decltype(e2.get_X().get_angle()), bu::quantity<bu::si::plane_angle>>::value));
    BOOST_TEST((std::is_same<decltype(e2.get_Declination()), quantity<bud::plane_angle>>::value));
}

BOOST_AUTO_TEST_CASE(equatorial_coord_quantities_hour_angle_constructor)
{
    //Create object of Right Ascension
    HourAngle<double, bu::quantity<bu::si::plane_angle>>
            ha(25.0 * bu::si::radian);

    //Check values
    BOOST_CHECK_CLOSE(ha.get_angle().value(), 25.0, 0.001);

    //Quantity stored as expected?
    BOOST_TEST((std::is_same<decltype(ha.get_angle()), bu::quantity<bu::si::plane_angle>>::value));

    //Make Equatorial Coordinate Check
    auto e1 = make_equatorial_coord(ha, 6.0 * bud::degree);

    //Check values
    BOOST_CHECK_CLOSE(e1.get_X().get_angle().value(), 25.0, 0.001);
    BOOST_CHECK_CLOSE(e1.get_Declination().value(), 6.0, 0.001);

    //Quantity stored as expected?
    BOOST_TEST((std::is_same<decltype(e1.get_X().get_angle()), bu::quantity<bu::si::plane_angle>>::value));
    BOOST_TEST((std::is_same<decltype(e1.get_Declination()), quantity<bud::plane_angle>>::value));

    //Equatorial Coordinate constructor
    equatorial_coord<double, HourAngle<double, bu::quantity<bu::si::plane_angle>>, quantity<bud::plane_angle>>
            e2(ha, 9.0 * bud::degrees);

    //Check values
    BOOST_CHECK_CLOSE(e2.get_X().get_angle().value(), 25.0, 0.001);
    BOOST_CHECK_CLOSE(e2.get_Declination().value(), 9.0, 0.001);

    //Quantity stored as expected?
    BOOST_TEST((std::is_same<decltype(e2.get_X().get_angle()), bu::quantity<bu::si::plane_angle>>::value));
    BOOST_TEST((std::is_same<decltype(e2.get_Declination()), quantity<bud::plane_angle>>::value));
}