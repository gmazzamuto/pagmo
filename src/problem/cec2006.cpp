/*****************************************************************************
 *   Copyright (C) 2004-2013 The PaGMO development team,                     *
 *   Advanced Concepts Team (ACT), European Space Agency (ESA)               *
 *   http://apps.sourceforge.net/mediawiki/pagmo                             *
 *   http://apps.sourceforge.net/mediawiki/pagmo/index.php?title=Developers  *
 *   http://apps.sourceforge.net/mediawiki/pagmo/index.php?title=Credits     *
 *   act@esa.int                                                             *
 *                                                                           *
 *   This program is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU General Public License as published by    *
 *   the Free Software Foundation; either version 2 of the License, or       *
 *   (at your option) any later version.                                     *
 *                                                                           *
 *   This program is distributed in the hope that it will be useful,         *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *   GNU General Public License for more details.                            *
 *                                                                           *
 *   You should have received a copy of the GNU General Public License       *
 *   along with this program; if not, write to the                           *
 *   Free Software Foundation, Inc.,                                         *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.               *
 *****************************************************************************/

#include <boost/math/constants/constants.hpp>

#include "../exceptions.h"
#include "../types.h"
#include "base.h"
#include "cec2006.h"

static int __check__(int N){
	if (N > 24 || N < 1) {
		pagmo_throw(value_error, "the problem id needs to be one of [1..24]");
	}
	return N;
}

namespace pagmo { namespace problem {

static const double PI = boost::math::constants::pi<double>();

// initialization of the problems, global constraints and inequality constraints dimension
const decision_vector::size_type cec2006::m_problems_dimension[] =
{13,20,10,5,4,2,10,2,7,8,2,3,5,10,3,5,6,9,15,24,7,22,9,2};
const constraint_vector::size_type cec2006::m_problems_c_dimension[] =
{9,2,1,6,5,2,8,2,4,6,1,1,3,3,2,38,4,13,5,20,6,20,6,2};
const constraint_vector::size_type cec2006::m_problems_ic_dimension[] =
{9,2,0,6,2,2,8,2,4,6,0,1,0,0,0,38,0,13,5,6,1,1,2,2};

/// Constructor
/**
 * Will construct one of the 24 CEC2006 problems
 *
 * @param[in] fun_id The problem id. One of [1,2,...,24]
 */
cec2006::cec2006(int fun_id):base(m_problems_dimension[__check__(fun_id)-1],0,1,m_problems_c_dimension[__check__(fun_id)-1],m_problems_ic_dimension[__check__(fun_id)-1]),m_problem_number(__check__(fun_id))
{
    // initialize best solution
    initialize_best();

    // set the bounds for the current problem
    switch(m_problem_number)
    {
    case 1:
    {
        const double lb[] = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
        const double ub[] = {1.,1.,1.,1.,1.,1.,1.,1.,1.,100.,100.,100.,1.};
        this->set_bounds(lb,ub);
        break;
    }
    case 2:
    {
        const double lb[] = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
        const double ub[] = {10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.};
        this->set_bounds(lb,ub);
        break;
    }
    case 3:
    {
        const double lb[] = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
        const double ub[] = {1.,1.,1.,1.,1.,1.,1.,1.,1.,1.};
        this->set_bounds(lb,ub);
        break;
    }
    case 4:
    {
        const double lb[] = {78.,33.,27.,27.,27.};
        const double ub[] = {102.,45.,45.,45.,45.};
        this->set_bounds(lb,ub);
        break;
    }
    case 5:
    {
        const double lb[] = {0.,0.,-0.55,-0.55};
        const double ub[] = {1.,1.,1.,1.};
        this->set_bounds(lb,ub);
        break;
    }
    case 6:
    {
        const double lb[] = {13.,0.};
        const double ub[] = {100.,100.};
        this->set_bounds(lb,ub);
        break;
    }
    case 7:
    {
        const double lb[] = {-10.,-10.,-10.,-10.,-10.,-10.,-10.,-10.,-10.,-10.};
        const double ub[] = {10.,10.,10.,10.,10.,10.,10.,10.,10.,10.};
        this->set_bounds(lb,ub);
        break;
    }
    case 8:
    {
        const double lb[] = {0.,0.};
        const double ub[] = {10.,10.};
        this->set_bounds(lb,ub);
        break;
    }
    case 9:
    {
        const double lb[] = {-10.,-10.,-10.,-10.,-10.,-10.,-10.};
        const double ub[] = {10.,10.,10.,10.,10.,10.,10.};
        this->set_bounds(lb,ub);
        break;
    }
    case 10:
    {
        const double lb[] = {100.,1000.,1000.,10.,10.,10.,10.,10.};
        const double ub[] = {10000.,10000.,10000.,1000.,1000.,1000.,1000.,1000.};
        this->set_bounds(lb,ub);
        break;
    }
    case 11:
    {
        const double lb[] = {-1.,-1.};
        const double ub[] = {1.,1.};
        this->set_bounds(lb,ub);
        break;
    }
    case 12:
    {
        const double lb[] = {0.,0.,0.};
        const double ub[] = {10.,10.,10.};
        this->set_bounds(lb,ub);
        break;
    }
    case 13:
    {
        const double lb[] = {-2.3,-2.3,-3.2,-3.2,-3.2};
        const double ub[] = {2.3,2.3,3.2,3.2,3.2};
        this->set_bounds(lb,ub);
        break;
    }
    case 14:
    {
        const double lb[] = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
        const double ub[] = {10.,10.,10.,10.,10.,10.,10.,10.,10.,10.};
        this->set_bounds(lb,ub);
        break;
    }
    case 15:
    {
        const double lb[] = {0.,0.,0.};
        const double ub[] = {10.,10.,10.};
        this->set_bounds(lb,ub);
        break;
    }
    case 16:
    {
        const double lb[] = {704.4148,68.6,0.,193.,25.};
        const double ub[] = {906.3855,288.88,134.75,287.0966,84.1988};
        this->set_bounds(lb,ub);
        break;
    }
    case 17:
    {
        const double lb[] = {0.,0.,340.,340.,-1000.,0.};
        const double ub[] = {400.,1000.,420.,420.,1000.,0.5236};
        this->set_bounds(lb,ub);
        break;
    }
    case 18:
    {
        const double lb[] = {-10.,-10.,-10.,-10.,-10.,-10.,-10.,-10.,0.};
        const double ub[] = {10.,10.,10.,10.,10.,10.,10.,10.,20.};
        this->set_bounds(lb,ub);
        break;
    }
    case 19:
    {
        const double lb[] = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
        const double ub[] = {10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.};
        this->set_bounds(lb,ub);
        break;
    }
    case 20:
    {
        const double lb[] = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
        const double ub[] = {10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.,10.};
        this->set_bounds(lb,ub);
        break;
    }
    case 21:
    {
        const double lb[] = {0.,0.,0.,100.,6.3,5.9,4.5};
        const double ub[] = {1000.,40.,40.,300.,6.7,6.4,6.25};
        this->set_bounds(lb,ub);
        break;
    }
    case 22:
    {
        const double lb[] = {0.,0.,0.,0.,0.,0.,0.,100.,100.,100.01,100.,100.,0.,0.,0.,0.01,0.01,-4.7,-4.7,-4.7,-4.7,-4.7};
        const double ub[] = {20000.,1e6,1e6,1e6,4e7,4e7,4e7,299.99,399.99,300,400,600,500,500,500,300.,400.,6.25,6.25,6.25,6.25,6.25};
        this->set_bounds(lb,ub);
        break;
    }
    case 23:
    {
        const double lb[] = {0.,0.,0.,0.,0.,0.,0.,0.,0.01};
        const double ub[] = {300.,300.,100.,200.,100.,300.,100.,200.,0.03};
        this->set_bounds(lb,ub);
        break;
    }
    case 24:
    {
        const double lb[] = {0.,0.};
        const double ub[] = {3.,4.};
        this->set_bounds(lb,ub);
        break;
    }
    default:
        pagmo_throw(value_error, "Error: There are only 24 test functions in this test suite!");
        break;
    }
}

/// Clone method.
base_ptr cec2006::clone() const
{
    return base_ptr(new cec2006(*this));
}

/// Implementation of the objective function.
void cec2006::objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    switch(m_problem_number)
    {
    case 1:
        this->g01_objfun_impl(f,x);
        break;
    case 2:
        this->g02_objfun_impl(f,x);
        break;
    case 3:
        this->g03_objfun_impl(f,x);
        break;
    case 4:
        this->g04_objfun_impl(f,x);
        break;
    case 5:
        this->g05_objfun_impl(f,x);
        break;
    case 6:
        this->g06_objfun_impl(f,x);
        break;
    case 7:
        this->g07_objfun_impl(f,x);
        break;
    case 8:
        this->g08_objfun_impl(f,x);
        break;
    case 9:
        this->g09_objfun_impl(f,x);
        break;
    case 10:
        this->g10_objfun_impl(f,x);
        break;
    case 11:
        this->g11_objfun_impl(f,x);
        break;
    case 12:
        this->g12_objfun_impl(f,x);
        break;
    case 13:
        this->g13_objfun_impl(f,x);
        break;
    case 14:
        this->g14_objfun_impl(f,x);
        break;
    case 15:
        this->g15_objfun_impl(f,x);
        break;
    case 16:
        this->g16_objfun_impl(f,x);
        break;
    case 17:
        this->g17_objfun_impl(f,x);
        break;
    case 18:
        this->g18_objfun_impl(f,x);
        break;
    case 19:
        this->g19_objfun_impl(f,x);
        break;
    case 20:
        this->g20_objfun_impl(f,x);
        break;
    case 21:
        this->g21_objfun_impl(f,x);
        break;
    case 22:
        this->g22_objfun_impl(f,x);
        break;
    case 23:
        this->g23_objfun_impl(f,x);
        break;
    case 24:
        this->g24_objfun_impl(f,x);
        break;
    default:
        pagmo_throw(value_error, "Error: There are only 24 test functions in this test suite!");
        break;
    }
}

/// Implementation of the constraint function.
void cec2006::compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    switch(m_problem_number)
    {
    case 1:
        this->g01_compute_constraints_impl(c,x);
        break;
    case 2:
        this->g02_compute_constraints_impl(c,x);
        break;
    case 3:
        this->g03_compute_constraints_impl(c,x);
        break;
    case 4:
        this->g04_compute_constraints_impl(c,x);
        break;
    case 5:
        this->g05_compute_constraints_impl(c,x);
        break;
    case 6:
        this->g06_compute_constraints_impl(c,x);
        break;
    case 7:
        this->g07_compute_constraints_impl(c,x);
        break;
    case 8:
        this->g08_compute_constraints_impl(c,x);
        break;
    case 9:
        this->g09_compute_constraints_impl(c,x);
        break;
    case 10:
        this->g10_compute_constraints_impl(c,x);
        break;
    case 11:
        this->g11_compute_constraints_impl(c,x);
        break;
    case 12:
        this->g12_compute_constraints_impl(c,x);
        break;
    case 13:
        this->g13_compute_constraints_impl(c,x);
        break;
    case 14:
        this->g14_compute_constraints_impl(c,x);
        break;
    case 15:
        this->g15_compute_constraints_impl(c,x);
        break;
    case 16:
        this->g16_compute_constraints_impl(c,x);
        break;
    case 17:
        this->g17_compute_constraints_impl(c,x);
        break;
    case 18:
        this->g18_compute_constraints_impl(c,x);
        break;
    case 19:
        this->g19_compute_constraints_impl(c,x);
        break;
    case 20:
        this->g20_compute_constraints_impl(c,x);
        break;
    case 21:
        this->g21_compute_constraints_impl(c,x);
        break;
    case 22:
        this->g22_compute_constraints_impl(c,x);
        break;
    case 23:
        this->g23_compute_constraints_impl(c,x);
        break;
    case 24:
        this->g24_compute_constraints_impl(c,x);
        break;
    default:
        pagmo_throw(value_error, "Error: There are only 24 test functions in this test suite!");
        break;
    }
}

std::string cec2006::get_name() const
{
    std::string retval("CEC2006 - g");
    retval.append(boost::lexical_cast<std::string>(m_problem_number));

    return retval;
}

/// Initialize the best known solutions.
void cec2006::initialize_best(void)
{
    switch(m_problem_number)
    {
    case 1:
    {
        const double x_vector[] = {1.,1.,1.,1.,1.,1.,1.,1.,1.,3.,3.,3.,1.};
        const double f_vector[] = {-15.};
        double c_vector[] = {0., 0., 0., -5., -5., -5., 0., 0., 0.};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);

        break;
    }
    case 2:
    {
        const double x_vector[] = {3.16246061572185, 3.12833142812967, 3.09479212988791, 3.06145059523469,
                                   3.02792915885555, 2.99382606701730, 2.95866871765285, 2.92184227312450,
                                   0.49482511456933, 0.48835711005490, 0.48231642711865, 0.47664475092742,
                                   0.47129550835493, 0.46623099264167, 0.46142004984199, 0.45683664767217,
                                   0.45245876903267, 0.44826762241853, 0.44424700958760, 0.44038285956317};
        const double f_vector[] = {-0.80361910412559};
        double c_vector[] = {-1.2878587085651816e-14, -120.06741615259264};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);
        break;
    }
    case 3:
    {
        const double x_vector[] = {0.31624357647283069, 0.316243577414338339, 0.316243578012345927, 0.316243575664017895,
                                   0.316243578205526066, 0.31624357738855069, 0.316243575472949512, 0.316243577164883938,
                                   0.316243578155920302, 0.316243576147374916};
        const double f_vector[] = {-1.00050010001000};
        double c_vector[] = {9.9999999999988987e-05};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);
        break;
    }
    case 4:
    {
        const double x_vector[] = {78,33,29.9952560256815985,45,36.7758129057882073};
        const double f_vector[] = {-3.066553867178332e+004};
        double c_vector[] = {0., -92., -11.159499691073137, -8.8405003089268632, -4.9999999999999964, -3.5527136788005009e-15};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);
        break;
    }
    case 5:
    {
        const double x_vector[] = {679.945148297028709,1026.06697600004691,0.118876369094410433,-0.39623348521517826};
        const double f_vector[] = {5126.4967140071};
        double c_vector[] = {9.9999999974897946e-05, 9.9999999974897946e-05, 9.9999999974897946e-05, -0.034890145690411378, -1.0651098543095887};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);
        break;
    }
    case 6:
    {
        const double x_vector[] = {14.09500000000000064,0.8429607892154795668};
        const double f_vector[] = {-6961.81387558015};
        double c_vector[] = {0., 0.};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);
        break;
    }
    case 7:
    {
        const double x_vector[] = {2.17199634142692, 2.3636830416034, 8.77392573913157, 5.09598443745173,
                                   0.990654756560493, 1.43057392853463, 1.32164415364306, 9.82872576524495,
                                   8.2800915887356, 8.3759266477347};
        const double f_vector[] = {24.30620906818};
        double c_vector[] = {5.6843418860808015e-14, -1.1723955140041653e-13, 3.907985046680551e-14, -6.0254023992456496e-12,
                             -7.1054273576010019e-15, -2.8421709430404007e-14, -6.1485036896036398, -50.023961731838071};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);
        break;
    }
    case 8:
    {
        const double x_vector[] = {1.22797135260752599, 4.24537336612274885};
        const double f_vector[] = {-0.0958250414180359};
        double c_vector[] = {-1.737459723297992, -0.16776326380511744};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);
        break;
    }
    case 9:
    {
        const double x_vector[] = {2.33049935147405174, 1.95137236847114592, -0.477541399510615805, 4.36572624923625874, -0.624486959100388983, 1.03813099410962173, 1.5942266780671519};
        const double f_vector[] = {680.630057374402};
        double c_vector[] = {-1.3766765505351941e-14, -252.56171634346606, -144.87817845461515, -2.4868995751603507e-14};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);
        break;
    }
    case 10:
    {
        const double x_vector[] = {579.306685017979589,1359.97067807935605,5109.97065743133317,182.01769963061534, 295.601173702746792, 217.982300369384632, 286.41652592786852, 395.601173702746735};
        const double f_vector[] = {7049.24802052867};
        double c_vector[] = {0, 0, -5.5511151231257827e-16, -1.4551915228366852e-11, -2.9103830456733704e-11, -1.1641532182693481e-10};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);
        break;
    }
    case 11:
    {
        const double x_vector[] = {-0.707036070037170616, 0.500000004333606807};
        const double f_vector[] = {0.7499};
        double c_vector[] = {9.9999999999988987e-05};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);
        break;
    }
    case 12:
    {
        const double x_vector[] = {5.,5.,5.};
        const double f_vector[] = {-1.};
        double c_vector[] = {-0.0625};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);
        break;
    }
    case 13:
    {
        const double x_vector[] = {-1.71714224003, 1.59572124049468, 1.8272502406271, -0.763659881912867, -0.76365986736498};
        const double f_vector[] = {0.053941514041898};
        double c_vector[] = {9.9999999994437871e-05, -0.00010000000000331966, 9.9999999998878764e-05};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);
        break;
    }
    case 14:
    {
        const double x_vector[] = {0.0406684113216282, 0.147721240492452, 0.783205732104114, 0.00141433931889084,
                                   0.485293636780388, 0.000693183051556082, 0.0274052040687766, 0.0179509660214818,
                                   0.0373268186859717, 0.0968844604336845};
        const double f_vector[] = {-47.7648884594915};
        double c_vector[] = {0.00010000000000109921, 9.9999999999544897e-05, 0.00010000000000043308};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);
        break;
    }
    case 15:
    {
        const double x_vector[] = {3.51212812611795133,0.216987510429556135,3.55217854929179921};
        const double f_vector[] = {961.715022289961};
        double c_vector[] = {9.9999999999766942e-05, 9.9999999989108801e-05};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);
        break;
    }
    case 16:
    {
        const double x_vector[] = {705.174537070090537, 68.5999999999999943, 102.899999999999991, 282.324931593660324,
                                   37.5841164258054832};
        const double f_vector[] = {-1.90515525853479};
        double c_vector[] = {-81.790353283003498, 0, 0, -5.6843418860808015e-14,
                             0, -192.13000000000002, -0.29331594739664624, -1035.8683840526032, -0.094075252933153664,
                             -23.660924747066847, -1.7844298057299284, -449.5725701942701, -337.68448248701077,
                             -239.32051751298917, -131.68954952441663, -133.26545047558335, -1.0081273474015813,
                             -4.4258726525984189, -0.0010113580124478661, -0.074988641987552146, -46.616183234373679,
                             -118.75981676562631, -47.15206111982161, -316.25993888017842, -187.97290376436615,
                             -329.2410962356339, -0.13924565212261086, -518.23575434787733, -1859.6857829062783,
                             -315.19021709372191, -5850.0391214556676, -12032.598878544331, -0.18271094712517674,
                             -0.14028905287482327, -68915.669999999998, 0, -9275494.7446969859, -67900.25530301407};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);
        break;
    }
    case 17:
    {
        const double x_vector[] = {201.784467214523659, 99.9999999999999005, 383.071034852773266, 420,
                                   -10.9076584514292652, 0.0731482312084287128};
        const double f_vector[] = {8853.53967480648};
        double c_vector[] = {9.5279025970285147e-05, 9.9999999889632818e-05, -7.5298006409596496e-05, 9.9999999605415724e-05};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);
        break;
    }
    case 18:
    {
        const double x_vector[] = {-0.657776192427943163, -0.153418773482438542, 0.323413871675240938, -0.946257611651304398,
                                   -0.657776194376798906, -0.753213434632691414, 0.323413874123576972, -0.346462947962331735,
                                   0.59979466285217542};
        const double f_vector[] = {-0.866025403784439};
        double c_vector[] = {0, -0.6402463624140452, 0, 0,
                             -0.64024636445565331, -1.5959455978986625e-16, -7.6327832942979512e-17, -0.64024636141023228,
                             0, -0.67204348836757655, -0.19398191412316787, -0.39453065073841909, -0.47149475433971377};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);
        break;
    }
    case 19:
    {
        const double x_vector[] = {1.66991341326291344e-17, 3.95378229282456509e-16, 3.94599045143233784, 1.06036597479721211e-16,
                                   3.2831773458454161, 9.99999999999999822, 1.12829414671605333e-17, 1.2026194599794709e-17,
                                   2.50706276000769697e-15, 2.24624122987970677e-15, 0.370764847417013987, 0.278456024942955571,
                                   0.523838487672241171, 0.388620152510322781,0.298156764974678579};
        const double f_vector[] = {32.6555929502463};
        double c_vector[] = {1.7763568394002505e-15, -0, -0, 8.8817841970012523e-16, -0};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);
        break;
    }
    case 20:
    {
        const double x_vector[] = {1.28582343498528086e-18, 4.83460302526130664e-34, 0, 0, 6.30459929660781851e-18,
                                   7.57192526201145068e-34, 5.03350698372840437e-34, 9.28268079616618064e-34, 0,
                                   1.76723384525547359e-17, 3.55686101822965701e-34, 2.99413850083471346e-34, 0.158143376337580827,
                                   2.29601774161699833e-19, 1.06106938611042947e-18, 1.31968344319506391e-18, 0.530902525044209539,
                                   0, 2.89148310257773535e-18, 3.34892126180666159e-18, 0, 0.310999974151577319,
                                   5.41244666317833561e-05, 4.84993165246959553e-16};
        const double f_vector[] = {0.20497940028563599};
        double c_vector[] = {9.9999999999766942e-05, -2.1972568189549347e-17, 1.5539704692828344e-18, 8.1753737821131767e-19,
                             9.9999999999766942e-05, -1.0383082213426958e-17, -2.992491915147666e-17, -3.20853810872953e-18,
                             0, 9.9999999999877964e-05, 9.9999999999840031e-05, 6.8665220979881771e-16,
                             9.9999999999988987e-05, -9.9999999999322853e-05, 0.14375363724895993, 1.7660316449634668e-19,
                             7.5785257203801829e-19, 2.2240466906989736e-18, 2.0929449795679412e-18, 0};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);
        break;
    }
    case 21:
    {
        const double x_vector[] = {193.724510070034967, 5.56944131553368433e-27, 17.3191887294084914, 100.047897801386839,
                                   6.68445185362377892, 5.99168428444264833, 6.21451648886070451};
        const double f_vector[] = {193.724510070035};
        double c_vector[] = {9.9999997473787516e-05, 0.00010000000111176632, 9.9999999999766942e-05, -9.9999999999766942e-05,
                             -9.9999999999766942e-05, -2.8421709430404007e-14};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);
        break;
    }
    case 22:
    {
        const double x_vector[] = {236.430975504001054, 135.82847151732463, 204.818152544824585, 6446.54654059436416,
                                   3007540.83940215595, 4074188.65771341929, 32918270.5028952882, 130.075408394314167,
                                   170.817294970528621, 299.924591605478554, 399.258113423595205, 330.817294971142758,
                                   184.51831230897065, 248.64670239647424, 127.658546694545862, 269.182627528746707,
                                   160.000016724090955, 5.29788288102680571, 5.13529735903945728, 5.59531526444068827,
                                   5.43444479314453499, 5.07517453535834395};
        const double f_vector[] = {236.430975504001};
        double c_vector[] = {-2.9260292649269104e-05, 9.1973692178726196e-05, -5.184859037399292e-05, -4.9985945224761963e-05, 7.2941184043884277e-05, 9.5665454864501953e-06, 5.6096352636814117e-05, 1.6726553440093994e-05, 5.4139643907546997e-05, -7.7500534302998858e-05, 1.6723476818469862e-05, 5.7372450426917965e-05, 5.7400810546504033e-05, 7.4797550418281844e-05, 7.4730862352545557e-05, -6.1559895403462406e-07, 6.1231858126120642e-06, -8.7799054654169595e-05, 9.5923077310544613e-05, -2.2079848349676467e-07};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);
        break;
    }
    case 23:
    {
        const double x_vector[] = {0.00510000000000259465, 99.9947000000000514, 9.01920162996045897e-18, 99.9999000000000535,
                                   0.000100000000027086086, 2.75700683389584542e-14, 99.9999999999999574, 200, 0.0100000100000100008};
        const double f_vector[] = {-400.055099999999584};
        double c_vector[] = {-0.00010000000000331966, 9.9999999999988987e-05, -9.9999999999507005e-05, -9.9999999974897946e-05,
                             -2.5000000001256605e-06, 0};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);
        break;
    }
    case 24:
    {
        static const double x_vector[] = {2.32952019747762,3.17849307411774};
        static const double f_vector[] = {-5.50801327159536};
        static const double c_vector[] = {-4.8849813083506888e-14, 1.7053025658242404e-13};

        this->set_best_known_solutions(x_vector,f_vector,c_vector);
        break;
    }
    default:
    {
        pagmo_throw(value_error, "Error: There are only 24 test functions in this test suite!");
        break;
    }

    }

}

// might be called add best know solution, and should take vectors
void cec2006::set_best_known_solutions(const double x[], const double f[], const double c[])
{
    m_best_known_decision_vector.resize(1);
    m_best_known_fitness_vector.resize(1);
    m_best_known_constraint_vector.resize(1);

    int x_dimension = m_problems_dimension[m_problem_number-1];
    int f_dimension = 1;
    int c_dimension = m_problems_c_dimension[m_problem_number-1];

    decision_vector best_known_decision;
    fitness_vector best_known_fitness;
    constraint_vector best_known_constraint;

    best_known_decision.resize(x_dimension);
    std::copy(x,x + x_dimension,best_known_decision.begin());

    best_known_fitness.resize(f_dimension);
    std::copy(f,f + f_dimension,best_known_fitness.begin());

    best_known_constraint.resize(c_dimension);
    std::copy(c,c + c_dimension,best_known_constraint.begin());

    m_best_known_decision_vector[0] = best_known_decision;
    m_best_known_fitness_vector[0] = best_known_fitness;
    m_best_known_constraint_vector[0] = best_known_constraint;
}

// -------------------------------------------

/// Implementation of the objective function.
void cec2006::g01_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    /* objective function */
    f[0] = 5.0 * (x[0] + x[1] + x[2] + x[3]) - 5.0 * (x[0] * x[0] + x[1] * x[1] + x[2] * x[2] + x[3] * x[3]);

    for (decision_vector::size_type j = 4; j < 13; j++)
        f[0] = f[0] - x[j];
}

/// Implementation of the constraint function.
void cec2006::g01_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    /* constraints g<=0 */
    c[0] = 2.0 * x[0] + 2.0 * x[1] + x[9] + x[10] - 10.;
    c[1] = 2.0 * x[0] + 2.0 * x[2] + x[9] + x[11] - 10.;
    c[2] = 2.0 * x[1] + 2.0 * x[2] + x[10] + x[11] - 10.;
    c[3] = -8.0 * x[0] + x[9];
    c[4] = -8.0 * x[1] + x[10];
    c[5] = -8.0 * x[2] + x[11];
    c[6] = -2.0 * x[3] - x[4] + x[9];
    c[7] = -2.0 * x[5] - x[6] + x[10];
    c[8] = -2.0 * x[7] - x[8] + x[11];
}

// -------------------------------------------

/// Implementation of the objective function.
void cec2006::g02_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    double nx = this->get_dimension();

    /* objective function */
    double f1 = 0.;
    double f2 = 1.;
    double f3 = 0.;

    for (int j=0; j<nx; j++) {
        f1 = f1 + pow(cos(x[j]), 4);
        f2 = f2 * cos(x[j]) * cos(x[j]);
        f3 = f3 + ((double) (j + 1)) * x[j] * x[j];
    }
    f[0] = - fabs((f1 - 2 * f2) / sqrt(f3));
}

/// Implementation of the constraint function.
void cec2006::g02_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    /* constraints g<=0 */
    double nx = this->get_dimension();

    double g1 = 1.;
    double g2 = 0.;

    for (int j=0; j<nx; j++) {
        g1 = g1 * x[j];
        g2 = g2 + x[j];
    }

    c[0] = 0.75 - g1;
    c[1] = g2 - 7.5 * ((double) nx);
}

// -------------------------------------------

/// Implementation of the objective function.
void cec2006::g03_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    /* objective function */
    double nx = this->get_dimension();

    double f1 = 1.;
    double f3 = sqrt((double) nx);

    for (int j=0; j<nx; j++) {
        f1 = f3 * f1 * x[j];
    }

    f[0] = - f1;
}

/// Implementation of the constraint function.
void cec2006::g03_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    double nx = this->get_dimension();

    double f2 = 0.;

    for (int j=0; j<nx; j++) {
        f2 = f2 + x[j] * x[j];
    }

    /* constraints h=0 */
    c[0] = f2 - 1.0;
}

// -------------------------------------------

/// Implementation of the objective function.
void cec2006::g04_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    /* objective function */
    f[0] = 5.3578547 * x[2] * x[2] + 0.8356891 * x[0] * x[4] + 37.293239 * x[0] - 40792.141;
}

/// Implementation of the constraint function.
void cec2006::g04_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    /* constraints g<=0 */
    c[0] = 85.334407 + 0.0056858 * x[1] * x[4] + 0.0006262 * x[0] * x[3] - 0.0022053 * x[2] * x[4] - 92.;
    c[1] = -85.334407 - 0.0056858 * x[1] * x[4] - 0.0006262 * x[0] * x[3] + 0.0022053 * x[2] * x[4];
    c[2] = 80.51249 + 0.0071317 * x[1] * x[4] + 0.0029955 * x[0] * x[1] + 0.0021813 * x[2] * x[2] - 110.;
    c[3] = -80.51249 - 0.0071317 * x[1] * x[4] - 0.0029955 * x[0] * x[1] - 0.0021813 * x[2] * x[2] + 90.;
    c[4] = 9.300961 + 0.0047026 * x[2] * x[4] + 0.0012547 * x[0] * x[2] + 0.0019085 * x[2] * x[3] - 25.;
    c[5] = -9.300961 - 0.0047026 * x[2] * x[4] - 0.0012547 * x[0] * x[2] - 0.0019085 * x[2] * x[3] + 20.;
}

// -------------------------------------------

/// Implementation of the objective function.
void cec2006::g05_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    /* objective function */
    f[0] = 3.0 * x[0] + 0.000001 * pow(x[0], 3) + 2.0 * x[1] + (0.000002 / 3.0) * pow(x[1], 3);
}

/// Implementation of the constraint function.
void cec2006::g05_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    /* constraints h=0 */
    c[0] = 1000.0 * sin(-x[2] - 0.25) + 1000.0 * sin(-x[3] - 0.25) + 894.8 - x[0];
    c[1] = 1000.0 * sin(x[2] - 0.25) + 1000.0 * sin(x[2] - x[3] - 0.25) + 894.8 - x[1];
    c[2] = 1000.0 * sin(x[3] - 0.25) + 1000.0 * sin(x[3] - x[2] - 0.25) + 1294.8;

    /* constraints g<=0 */
    c[3] = -x[3] + x[2] - 0.55;
    c[4] = -x[2] + x[3] - 0.55;
}

// -------------------------------------------

/// Implementation of the objective function.
void cec2006::g06_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    /* objective function */
    f[0] = pow((x[0] - 10.), 3) + pow((x[1] - 20.), 3);
}

/// Implementation of the constraint function.
void cec2006::g06_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    /* constraints g<=0 */
    c[0] = 100. - (x[0] - 5.) * (x[0] - 5.) - (x[1] - 5.) * (x[1] - 5.);
    c[1] = (x[0] - 6.) * (x[0] - 6.) + (x[1] - 5.) * (x[1] - 5.) - 82.81;
}

// -------------------------------------------

/// Implementation of the objective function.
void cec2006::g07_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    /* objective function */
    f[0] = x[0] * x[0] + x[1] * x[1] + x[0] * x[1] - 14.0 * x[0] - 16.0 * x[1] + (x[2] - 10.0) * (x[2] - 10.0) +
            4.0 * (x[3] - 5.0) * (x[3] - 5.0) + (x[4] - 3.0) * (x[4] - 3.0) + 2.0 * (x[5] - 1.0) * (x[5] - 1.0) +
            5.0 * x[6] * x[6] + 7.0 * (x[7] - 11) * (x[7] - 11) + 2.0 * (x[8] - 10.0) * (x[8] - 10.0) +
            (x[9] - 7.0) * (x[9] - 7.0) + 45.;
}

/// Implementation of the constraint function.
void cec2006::g07_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    /* constraints g<=0 */
    c[0] = -105.0 + 4.0 * x[0] + 5.0 * x[1] - 3.0 * x[6] + 9.0 * x[7];
    c[1] = 10.0 * x[0] - 8.0 * x[1] - 17.0 * x[6] + 2.0 * x[7];
    c[2] = -8.0 * x[0] + 2.0 * x[1] + 5.0 * x[8] - 2.0 * x[9] - 12.0;
    c[3] = 3.0 * (x[0] - 2.0) * (x[0] - 2.0) + 4.0 * (x[1] - 3.0) * (x[1] - 3.0) + 2.0 * x[2] * x[2] - 7.0 * x[3] - 120.0;
    c[4] = 5.0 * x[0] * x[0] + 8.0 * x[1] + (x[2] - 6.0) * (x[2] - 6.0) - 2.0 * x[3] - 40.0;
    c[5] = x[0] * x[0] + 2.0 * (x[1] - 2.0) * (x[1] - 2.0) - 2.0 * x[0] * x[1] + 14.0 * x[4] - 6.0 * x[5];
    c[6] = 0.5 * (x[0] - 8.0) * (x[0] - 8.0) + 2.0 * (x[1] - 4.0) * (x[1] - 4.0) + 3.0 * x[4] * x[4] - x[5] - 30.0;
    c[7] = -3.0 * x[0] + 6.0 * x[1] + 12.0 * (x[8] - 8.0) * (x[8] - 8.0) - 7.0 * x[9];
}

// -------------------------------------------

/// Implementation of the objective function.
void cec2006::g08_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    /* objective function */
    f[0] = - pow(sin(2 * PI * x[0]), 3) * sin (2 * PI * x[1]) / (pow(x[0], 3) * (x[0] + x[1]));
}

/// Implementation of the constraint function.
void cec2006::g08_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    /* constraints g<=0 */
    c[0] = x[0] * x[0] - x[1] + 1.0;
    c[1] = 1.0 - x[0] + (x[1] - 4.0) * (x[1] - 4.0);
}

// -------------------------------------------

/// Implementation of the objective function.
void cec2006::g09_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    /* objective function */
    f[0] = (x[0] - 10.0) * (x[0] - 10.0) + 5.0 * (x[1] - 12.0) * (x[1] - 12.0) + pow(x[2], 4) +
            3.0 * (x[3] - 11.0) * (x[3] - 11.0) + 10.0 * pow(x[4], 6) + 7.0 * x[5] * x[5] +
            pow(x[6], 4) - 4.0 * x[5] * x[6] - 10.0 * x[5] - 8.0 * x[6];
}

/// Implementation of the constraint function.
void cec2006::g09_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    /* constraints g<=0 */
    c[0] = -127.0 + 2 * x[0] * x[0] + 3.0 * pow(x[1], 4) + x[2] + 4.0 * x[3] * x[3] + 5.0 * x[4];
    c[1] = -282.0 + 7.0 * x[0] + 3.0 * x[1] + 10.0 * x[2] * x[2] + x[3] - x[4];
    c[2] = -196.0 + 23.0 * x[0] + x[1] * x[1] + 6.0 * x[5] * x[5] - 8.0 * x[6];
    c[3] = 4.0 * x[0] * x[0] + x[1] * x[1] - 3.0 * x[0] * x[1] + 2.0 * x[2] * x[2] + 5.0 * x[5] - 11.0 * x[6];
}

// -------------------------------------------


/// Implementation of the objective function.
void cec2006::g10_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    /* objective function */
    f[0] = x[0] + x[1] + x[2];
}

/// Implementation of the constraint function.
void cec2006::g10_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    /* constraints g<=0 */
    c[0] = -1.0 + 0.0025 * (x[3] + x[5]);
    c[1] = -1.0 + 0.0025 * (x[4] + x[6] - x[3]);
    c[2] = -1.0 + 0.01 * (x[7] - x[4]);
    c[3] = -x[0] * x[5] + 833.33252 * x[3] + 100.0 * x[0] - 83333.333;
    c[4] = -x[1] * x[6] + 1250.0 * x[4] + x[1] * x[3] - 1250.0 * x[3];
    c[5] = -x[2] * x[7] + 1250000.0 + x[2] * x[4] - 2500.0 * x[4];
}

// -------------------------------------------

/// Implementation of the objective function.
void cec2006::g11_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    /* objective function */
    f[0] = x[0] * x[0] + (x[1] - 1.0) * (x[1] - 1.0);
}

/// Implementation of the constraint function.
void cec2006::g11_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    /* constraints h=0 */
    c[0] = x[1] - x[0] * x[0];
}

// -------------------------------------------

/// Implementation of the objective function.
void cec2006::g12_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    /* objective function */
    f[0] = - (100. - (x[0] - 5.) * (x[0] - 5.) - (x[1] - 5.) * (x[1] - 5.) - (x[2] - 5.) * (x[2] - 5.)) / 100.;
}

/// Implementation of the constraint function.
void cec2006::g12_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    double gt;

    /* constraints g<=0 */
    c[0] = (x[0] - 1.) * (x[0] - 1.) + (x[1] - 1.) * (x[1] - 1.) + (x[2] - 1.) * (x[2] - 1.) - 0.0625;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            for (int k = 1; k <= 9; k++){
                gt = (x[0] - i) * (x[0] - i) + (x[1] - j) * (x[1] - j) + (x[2] - k) * (x[2] - k) - 0.0625;
                if (gt < c[0])
                    c[0] = gt;
            }
        }
    }
}

// -------------------------------------------

/// Implementation of the objective function.
void cec2006::g13_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    /* objective function */
    f[0] = exp(x[0] * x[1] * x[2] * x[3] * x[4]);
}

/// Implementation of the constraint function.
void cec2006::g13_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    /* constraints h(x) = 0 */
    c[0] = x[0] * x[0] + x[1] * x[1] + x[2] * x[2] + x[3] * x[3] + x[4] * x[4] - 10.0;
    c[1] = x[1] * x[2] - 5.0 * x[3] * x[4];
    c[2] = pow(x[0], 3) + pow(x[1], 3) + 1.0;
}

// -------------------------------------------

/// Implementation of the objective function.
void cec2006::g14_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    double sumlog = 0.;
    double sum = 0.;
    double C[10] = {-6.089,-17.164,-34.054,-5.914,-24.721,-14.986,-24.100,-10.708,-26.662,-22.179};

    /* objective function */
    for (int i = 0; i < 10; i++)
        sumlog += x[i];
    for (int i = 0; i < 10; i++)
        sum += x[i] * (C[i] + log (x[i] / sumlog));
    f[0] = sum;
}

/// Implementation of the constraint function.
void cec2006::g14_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    /* constraints h=0 */
    c[0] = x[0] + 2.0 * x[1] + 2.0 * x[2] + x[5] + x[9] - 2.0;
    c[1] = x[3] + 2.0 * x[4] + x[5] + x[6] - 1.0;
    c[2] = x[2] + x[6] + x[7] + 2.0 * x[8] + x[9] - 1.0;
}

// -------------------------------------------

/// Implementation of the objective function.
void cec2006::g15_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    /* objective function */
    f[0] = 1000.0 - pow(x[0], 2.0) - 2.0 * x[1] * x[1] - x[2] * x[2] - x[0] * x[1] - x[0] * x[2];
}

/// Implementation of the constraint function.
void cec2006::g15_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    /* constraints h=0 */
    c[0] = pow(x[0], 2.0) + pow(x[1], 2.0) + pow(x[2], 2.0) - 25.0;
    c[1] = 8.0 * x[0] + 14.0 * x[1] + 7.0 * x[2] - 56.0;
}

// -------------------------------------------

/// Implementation of the objective function.
void cec2006::g16_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    double C[17], Y[17];

    double x1 = x[0];
    double x2 = x[1];
    double x3 = x[2];
    double x4 = x[3];
    double x5 = x[4];

    Y[0] = x2 + x3 + 41.6;
    C[0] = 0.024 * x4 - 4.62;
    Y[1] = (12.5 / C[0]) + 12.0;
    C[1] = 0.0003535 * pow(x1, 2.0) + 0.5311 * x1 + 0.08705 * Y[1] * x1;
    C[2] = 0.052 * x1 + 78.0 + 0.002377 * Y[1] * x1;
    Y[2] = C[1] / C[2];
    Y[3] = 19.0 * Y[2];
    C[3] = 0.04782 * (x1 - Y[2]) + ((0.1956 * pow(x1 - Y[2], 2.0)) / x2) + 0.6376 * Y[3] + 1.594 * Y[2];
    C[4] = 100 * x2;
    C[5] = x1 - Y[2] - Y[3];
    C[6] = 0.950 - (C[3] / C[4]);
    Y[4] = C[5] * C[6];
    Y[5] = x1 - Y[4] - Y[3] - Y[2];
    C[7] = (Y[4] + Y[3]) * 0.995;
    Y[6] = C[7] / Y[0];
    Y[7] = C[7] / 3798.0;
    C[8] = Y[6] - (0.0663 * Y[6] / Y[7]) - 0.3153;
    Y[8] = (96.82 / C[8]) + 0.321 * Y[0];
    Y[9] = 1.29 * Y[4] + 1.258 * Y[3] + 2.29 * Y[2] + 1.71 * Y[5];
    Y[10] = 1.71 * x1 - 0.452 * Y[3] + 0.580 * Y[2];
    C[9] = 12.3 / 752.3;
    C[10] = 1.75 * Y[1] * 0.995 * x1;
    C[11] = 0.995 * Y[9] + 1998.0;
    Y[11] = C[9] * x1 + (C[10] / C[11]);
    Y[12] = C[11] - 1.75 * Y[1];
    Y[13] = 3623.0 + 64.4 * x2 + 58.4 * x3 + (146312.0 / (Y[8] + x5));
    C[12] = 0.995 * Y[9] + 60.8 * x2 + 48 * x4 - 0.1121 * Y[13] - 5095.0;
    Y[14] = Y[12] / C[12];
    Y[15] = 148000.0 - 331000.0 * Y[14] + 40.0 * Y[12] - 61.0 * Y[14] * Y[12];
    C[13] = 2324 * Y[9] - 28740000 * Y[1];
    Y[16] = 14130000 - 1328.0 * Y[9] - 531.0 * Y[10] + (C[13] / C[11]);
    C[14] = (Y[12] / Y[14]) - (Y[12] / 0.52);
    C[15] = 1.104 - 0.72 * Y[14];
    C[16] = Y[8] + x5;

    /* objective function */
    f[0] = 0.0000005843 * Y[16] - 0.000117 * Y[13] - 0.1365 - 0.00002358 * Y[12] - 0.000001502 * Y[15] - 0.0321 * Y[11] - 0.004324 * Y[4] - 0.0001 * (C[14] / C[15]) - 37.48 * (Y[1] / C[11]);
    f[0] = -f[0]; /* Max-->Min, Modified by Jane,Nov 22 2005 */
}

/// Implementation of the constraint function.
void cec2006::g16_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    double C[17];
    double Y[17];

    double x1 = x[0];
    double x2 = x[1];
    double x3 = x[2];
    double x4 = x[3];
    double x5 = x[4];

    Y[0] = x2 + x3 + 41.6;
    C[0] = 0.024 * x4 - 4.62;
    Y[1] = (12.5 / C[0]) + 12.0;
    C[1] = 0.0003535 * pow(x1, 2.0) + 0.5311 * x1 + 0.08705 * Y[1] * x1;
    C[2] = 0.052 * x1 + 78.0 + 0.002377 * Y[1] * x1;
    Y[2] = C[1] / C[2];
    Y[3] = 19.0 * Y[2];
    C[3] = 0.04782 * (x1 - Y[2]) + ((0.1956 * pow(x1 - Y[2], 2.0)) / x2) + 0.6376 * Y[3] + 1.594 * Y[2];
    C[4] = 100 * x2;
    C[5] = x1 - Y[2] - Y[3];
    C[6] = 0.950 - (C[3] / C[4]);
    Y[4] = C[5] * C[6];
    Y[5] = x1 - Y[4] - Y[3] - Y[2];
    C[7] = (Y[4] + Y[3]) * 0.995;
    Y[6] = C[7] / Y[0];
    Y[7] = C[7] / 3798.0;
    C[8] = Y[6] - (0.0663 * Y[6] / Y[7]) - 0.3153;
    Y[8] = (96.82 / C[8]) + 0.321 * Y[0];
    Y[9] = 1.29 * Y[4] + 1.258 * Y[3] + 2.29 * Y[2] + 1.71 * Y[5];
    Y[10] = 1.71 * x1 - 0.452 * Y[3] + 0.580 * Y[2];
    C[9] = 12.3 / 752.3;
    C[10] = 1.75 * Y[1] * 0.995 * x1;
    C[11] = 0.995 * Y[9] + 1998.0;
    Y[11] = C[9] * x1 + (C[10] / C[11]);
    Y[12] = C[11] - 1.75 * Y[1];
    Y[13] = 3623.0 + 64.4 * x2 + 58.4 * x3 + (146312.0 / (Y[8] + x5));
    C[12] = 0.995 * Y[9] + 60.8 * x2 + 48 * x4 - 0.1121 * Y[13] - 5095.0;
    Y[14] = Y[12] / C[12];
    Y[15] = 148000.0 - 331000.0 * Y[14] + 40.0 * Y[12] - 61.0 * Y[14] * Y[12];
    C[13] = 2324 * Y[9] - 28740000 * Y[1];
    Y[16] = 14130000 - 1328.0 * Y[9] - 531.0 * Y[10] + (C[13] / C[11]);
    C[14] = (Y[12] / Y[14]) - (Y[12] / 0.52);
    C[15] = 1.104 - 0.72 * Y[14];
    C[16] = Y[8] + x5;

    /* constraints g(x) <= 0 */
    c[0] = -Y[3] + (0.28 / 0.72) * Y[4];
    c[1] = -1.5 * x2 + x3;
    c[2] = -21.0 + 3496.0 * (Y[1] / C[11]);
    c[3] = -(62212.0 / C[16]) + 110.6 + Y[0];
    c[4] = 213.1 - Y[0];
    c[5] = Y[0] - 405.23;
    c[6] = 17.505 - Y[1];
    c[7] = Y[1] - 1053.6667;
    c[8] = 11.275 - Y[2];
    c[9] = Y[2] - 35.03;
    c[10] = 214.228 - Y[3];
    c[11] = Y[3] - 665.585;
    c[12] = 7.458 - Y[4];
    c[13] = Y[4] - 584.463;
    c[14] = 0.961 - Y[5];
    c[15] = Y[5] - 265.916;
    c[16] = 1.612 - Y[6];
    c[17] = Y[6] - 7.046;
    c[18] = 0.146 - Y[7];
    c[19] = Y[7] - 0.222;
    c[20] = 107.99 - Y[8];
    c[21] = Y[8] - 273.366;
    c[22] = 922.693 - Y[9];
    c[23] = Y[9] - 1286.105;
    c[24] = 926.832 - Y[10];
    c[25] = Y[10] - 1444.046;
    c[26] = 18.766 - Y[11];
    c[27] = Y[11] - 537.141;
    c[28] = 1072.163 - Y[12];
    c[29] = Y[12] - 3247.039;
    c[30] = 8961.448 - Y[13];
    c[31] = Y[13] - 26844.086;
    c[32] = 0.063 - Y[14];
    c[33] = Y[14] - 0.386;
    c[34] = 71084.33 - Y[15];
    c[35] = Y[15] - 140000.0;
    c[36] = 2802713.0 - Y[16];
    c[37] = Y[16] - 12146108.0;
}

// -------------------------------------------

/// Implementation of the objective function.
void cec2006::g17_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    double f1=0;
    double f2=0;

    double x1 = x[0];
    double x2 = x[1];
    double x3 = x[2];
    double x4 = x[3];
    double x6 = x[5];

    double aux1 = 300.0 - (((x3 * x4) * cos(1.48477 - x6)) - ((0.90798 * pow(x3, 2.0)) * cos(1.47588))) / 131.078;
    double aux2 = -(((x3 * x4)  * cos(1.48477 + x6)) - ((0.90798 * pow(x4, 2.0))  * cos(1.47588)))/ 131.078;

    /* objective fucntion */
    if (x1 >= 0.0 && x1 < 300.0) {
        f1 = 30.0 * aux1;
    } else {
        if (x1 >= 300.0 && x1 <= 400.0) {
            f1 = 31.0 * aux1;
        }
    }
    if (x2 >= 0.0 && x2 < 100.0) {
        f2 = 28.0 * aux2;
    } else {
        if (x2 >= 100.0 && x2 < 200.0) {
            f2 = 29.0 * aux2;
        } else {
            if (x2 >= 200.0 && x2 <= 1000.0) {
                f2 = 30.0 * aux2;
            }
        }
    }
    f[0] = f1 + f2;
}

/// Implementation of the constraint function.
void cec2006::g17_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    double x1 = x[0];
    double x2 = x[1];
    double x3 = x[2];
    double x4 = x[3];
    double x5 = x[4];
    double x6 = x[5];

    double aux1 = 300.0 - (((x3 * x4) * cos (1.48477 - x6)) - ((0.90798 * pow (x3, 2.0)) * cos (1.47588))) / 131.078;
    double aux2 = -(((x3 * x4)  * cos (1.48477 + x6)) - ((0.90798 * pow (x4, 2.0))  * cos (1.47588)))/ 131.078;
    double aux5 = -(((x3 * x4)  * sin (1.48477 + x6)) - ((0.90798 * pow (x4, 2.0))  * sin (1.47588)))/ 131.078;
    double aux4 = 200.0 - (((x3 * x4)  * sin (1.48477 - x6)) - ((0.90798 * pow (x3, 2.0))  * sin (1.47588)))/ 131.078;

    /* constraint function h = 0 */
    c[0] = aux1 - x1;
    c[1] = aux2 - x2;
    c[2] = aux5 - x5;
    c[3] = aux4;
}

// -------------------------------------------

/// Implementation of the objective function.
void cec2006::g18_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    /* objective function */
    f[0] = - 0.5 * (x[0] * x[3] - x[1] * x[2] + x[2] * x[8] - x[4] * x[8] + x[4] * x[7] - x[5] * x[6]);
}

/// Implementation of the constraint function.
void cec2006::g18_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    /* constraint function g <= 0 */
    c[0] = -1.0 + pow(x[2], 2.0) + pow(x[3], 2.0);
    c[1] = -1.0 + pow(x[8], 2.0);
    c[2] = -1.0 + pow(x[4], 2.0) + pow(x[5], 2.0);
    c[3] = -1.0 + pow(x[0], 2.0) + pow(x[1] - x[8], 2.0);
    c[4] = -1.0 + pow(x[0] - x[4], 2.0) + pow(x[1] - x[5], 2.0);
    c[5] = -1.0 + pow(x[0] - x[6], 2.0) + pow(x[1] - x[7], 2.0);
    c[6] = -1.0 + pow(x[2] - x[4], 2.0) + pow(x[3] - x[5], 2.0);
    c[7] = -1.0 + pow(x[2] - x[6], 2.0) + pow(x[3] - x[7], 2.0);
    c[8] = -1.0 + pow(x[6], 2.0) + pow(x[7] - x[8], 2.0);
    c[9] = -x[0] * x[3] + x[1] * x[2];
    c[10] = -x[2] * x[8];
    c[11] = x[4] * x[8];
    c[12] = -x[4] * x[7] + x[5] * x[6];
}

// -------------------------------------------

/// Implementation of the objective function.
void cec2006::g19_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    double sum1 = 0.0;
    double sum2 = 0.0;
    double sum3 = 0.0;

    double B[10] = {-40.0,-2.0,-0.25,-4.0,-4.0,-1.0,-40.0,-60.0,5.0,1.0};
    double C[5][5] = {{30.0,-20.0,-10.0,32.0,-10.0},
                      {-20.0,39.0,-6.0,-31.0,32.0},
                      {-10.0,-6.0,10.0,-6.0,-10.0},
                      {32.0,-31.0,-6.0,39.0,-20.0},
                      {-10.0,32.0,-10.0,-20.0,30.0}
                     };
    double D[5] = {4.0,8.0,10.0,6.0,2.0};

    /* objective function */
    for (int i=0; i<10; i++) {
        sum1 += B[i] * x[i];
    }
    for (int i=0; i<5; i++) {
        for (int j = 0; j < 5; j++) {
            sum2 += C[i][j] * x[10 + i] * x[10 + j];
        }
    }
    for (int i=0; i<5; i++) {
        sum3 += D[i] * pow (x[10 + i], 3.0);
    }

    f[0] = sum1 - sum2 - 2.0 * sum3;
    f[0] = -f[0];
}

/// Implementation of the constraint function.
void cec2006::g19_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    double sum1 = 0.;
    double sum2 = 0.;

    double A[10][5] = {{-16.0,2.0,0.0,1.0,0.0},
                       {0.0,-2.0,0.0,0.4,2.0},
                       {-3.5,0.0,2.0,0.0,0.0},
                       {0.0,-2.0,0.0,-4.0,-1.0},
                       {0.0,-9.0,-2.0,1.0,-2.8},
                       {2.0,0.0,-4.0,0.0,0.0},
                       {-1.0,-1.0,-1.0,-1.0,-1.0},
                       {-1.0,-2.0,-3.0,-2.0,-1.0},
                       {1.0,2.0,3.0,4.0,5.0},
                       {1.0,1.0,1.0,1.0,1.0}
                      };

    double C[5][5] = {{30.0,-20.0,-10.0,32.0,-10.0},
                      {-20.0,39.0,-6.0,-31.0,32.0},
                      {-10.0,-6.0,10.0,-6.0,-10.0},
                      {32.0,-31.0,-6.0,39.0,-20.0},
                      {-10.0,32.0,-10.0,-20.0,30.0}
                     };

    double D[5] = {4.0,8.0,10.0,6.0,2.0};
    double E[5] = {-15.0,-27.0,-36.0,-18.0,-12.0};

    /* constraints g <= 0 */
    for (int j = 0; j < 5; j++) {
        sum1 = 0.0;
        for (int i = 0; i < 5; i++)
            sum1 += C[i][j] * x[10 + i];
        sum2 = 0.0;
        for (int i = 0; i < 10; i++)
            sum2 += A[i][j] * x[i];
        c[j] = -((2.0 * sum1) + (3.0 * D[j] * pow (x[10 + j], 2.0)) + E[j] - sum2);
    }
}

// -------------------------------------------

/// Implementation of the objective function.
void cec2006::g20_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    double A[24] = {0.0693,0.0577,0.05,0.2,0.26,0.55,0.06,0.1,0.12,0.18,0.1,0.09,
                    0.0693,0.0577,0.05,0.2,0.26,0.55,0.06,0.1,0.12,0.18,0.1,0.09};

    /* objective function */
    f[0] = 0.0;
    for (int j=0; j<24; j++) {
        f[0] += A[j] * x[j];
    }
}

/// Implementation of the constraint function.
void cec2006::g20_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    double sum1, sum2, sumtotal;

    double B[24] = {44.094,58.12,58.12,137.4,120.9,170.9,62.501,84.94,133.425,82.507,46.07,60.097,
                    44.094,58.12,58.12,137.4,120.9,170.9,62.501,84.94,133.425,82.507,46.07,60.097};
    double C[12] = {123.7,31.7,45.7,14.7,84.7,27.7,49.7,7.1,2.1,17.7,0.85,0.64};
    double D[12] = {31.244,36.12,34.784,92.7,82.7,91.6,56.708,82.7,80.8,64.517,49.4,49.1};
    double E[6] = {0.1,0.3,0.4,0.3,0.6,0.3};

    /* constraints h(x) = 0 */
    sum1 = 0.0;
    for (int j = 0; j < 12; j++)
        sum1 += x[j] / B[j];
    sum2 = 0.0;
    for (int j = 12; j < 24; j++)
        sum2 += x[j] / B[j];
    for (int i = 0; i < 12; i++)
        c[i] = (x[i + 12] / (B[i + 12] * sum2)) - ((C[i] * x[i]) / (40.0 * B[i] * sum1));
    sumtotal = 0.0;
    for (int j = 0; j < 24; j++)
        sumtotal += x[j];
    c[12] = sumtotal - 1.0;
    sum1 = 0.0;
    for (int j = 0; j < 12; j++)
        sum1 += x[j] / D[j];
    sum2 = 0.0;
    for (int j = 12; j < 24; j++)
        sum2 += x[j] / B[j];
    c[13] = sum1 + (0.7302 * 530.0 * (14.7 / 40)) * sum2 - 1.671;

    /* constraints g(x) <= 0 */
    for (int j = 0; j < 3; j++)
        c[14 + j] = (x[j] + x[j + 12]) / (sumtotal + E[j]);
    for (int j = 3; j < 6; j++)
        c[14 + j] = (x[j + 3] + x[j + 15]) / (sumtotal + E[j]);
}

// -------------------------------------------

/// Implementation of the objective function.
void cec2006::g21_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    /* objective function */
    f[0] = x[0];
}

/// Implementation of the constraint function.
void cec2006::g21_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    /* constraint functions h(x) = 0 */
    c[0] = -300.0 * x[2] + 7500 * x[4] - 7500 * x[5] - 25.0 * x[3] * x[4] + 25.0 * x[3] * x[5] + x[2] * x[3];
    c[1] = 100.0 * x[1] + 155.365 * x[3] + 2500 * x[6] - x[1] * x[3] - 25.0 * x[3] * x[6] - 15536.5;
    c[2] = -x[4] + log(-x[3] + 900.0);
    c[3] = -x[5] + log(x[3] + 300.0);
    c[4] = -x[6] + log(-2.0 * x[3] + 700.0);

    /* constraint functions g(x) <= 0 */
    c[5] = -x[0] + 35.0 * pow(x[1], 0.6) + 35.0 * pow(x[2], 0.6);
}

// -------------------------------------------

/// Implementation of the objective function.
void cec2006::g22_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    /* objective function */
    f[0] = x[0];
}

/// Implementation of the constraint function.
void cec2006::g22_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    /* constraint functions h(x) = 0 */
    c[0] = x[4] - 100000.0 * x[7] + 10000000.0;
    c[1] = x[5] + 100000.0 * x[7] - 100000.0 * x[8];
    c[2] = x[6] + 100000.0 * x[8] - 50000000.0;
    c[3] = x[4] + 100000.0 * x[9] - 33000000.0;
    c[4] = x[5] + 100000 * x[10] - 44000000.0;
    c[5] = x[6] + 100000 * x[11] - 66000000.0;
    c[6] = x[4] - 120.0 * x[1] * x[12];
    c[7] = x[5] - 80.0 * x[2] * x[13];
    c[8] = x[6] - 40.0 * x[3] * x[14];
    c[9] = x[7] - x[10] + x[15];
    c[10] = x[8] - x[11] + x[16];
    c[11] = -x[17] + log(x[9] - 100.0);
    c[12] = -x[18] + log(-x[7] + 300.0);
    c[13] = -x[19] + log(x[15]);
    c[14] = -x[20] + log(-x[8] + 400.0);
    c[15] = -x[21] + log(x[16]);
    c[16] = -x[7] - x[9] + x[12] * x[17] - x[12] * x[18] + 400.0;
    c[17] = x[7] - x[8] - x[10] + x[13] * x[19] - x[13] * x[20] + 400.0;
    c[18] = x[8] - x[11] - 4.60517 * x[14] + x[14] * x[21] + 100.0;

    /* constraint functions g(x) <= 0 */
    c[19] = -x[0] + pow(x[1], 0.6) + pow(x[2], 0.6) + pow(x[3], 0.6);
}

// -------------------------------------------

/// Implementation of the objective function.
void cec2006::g23_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    /* objective function */
    f[0] = -9.0 * x[4] - 15.0 * x[7] + 6.0 * x[0] + 16.0 * x[1] + 10.0 * (x[5] + x[6]);
}

/// Implementation of the constraint function.
void cec2006::g23_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    /* constraint functions h(x) = 0 */
    c[0] = x[0] + x[1] - x[2] - x[3];
    c[1] = 0.03 * x[0] + 0.01 * x[1] - x[8] * (x[2] + x[3]);
    c[2] = x[2] + x[5] - x[4];
    c[3] = x[3] + x[6] - x[7];

    /* constraint functions g(x) <= 0 */
    c[4] = x[8] * x[2] + 0.02 * x[5] - 0.025 * x[4];
    c[5] = x[8] * x[3] + 0.02 * x[6] - 0.015 * x[7];
}

// -------------------------------------------

/// Implementation of the objective function.
void cec2006::g24_objfun_impl(fitness_vector &f, const decision_vector &x) const
{
    /* objective function */
    f[0] = -x[0] - x[1];
}

/// Implementation of the constraint function.
void cec2006::g24_compute_constraints_impl(constraint_vector &c, const decision_vector &x) const
{
    /* constraint functions g(x) <= 0 */
    c[0] = -2.0 * pow (x[0], 4.0) + 8.0 * pow (x[0], 3.0) - 8.0 * pow (x[0], 2.0) + x[1] - 2.0;
    c[1] = -4.0 * pow (x[0], 4.0) + 32.0 * pow (x[0], 3.0) - 88.0 * pow (x[0], 2.0) + 96.0 * x[0] + x[1] - 36.0;
}

// -------------------------------------------

/// Get the best known constraint vector.
/**
 * @return the best known constraint vector for the problem.
 *
 */
const std::vector<constraint_vector>& cec2006::get_best_known_c_vector(void) const
{
    return this->m_best_known_constraint_vector;
}

/// Get the best known decision vector.
/**
 * @return the best known decision vector for the problem.
 *
 */
const std::vector<decision_vector>& cec2006::get_best_known_x_vector(void) const
{
    return this->m_best_known_decision_vector;
}

/// Get the best known fitness vector.
/**
 * @return the best known fitness vector for the problem.
 *
 */
const std::vector<fitness_vector>& cec2006::get_best_known_f_vector(void) const
{
    return this->m_best_known_fitness_vector;
}

///// Initialize the best known fitness, decision and constraints vectors
///**
// * This method should be called to set the best known fitness. If it has not been reimplemented
// * in a derived class, then best known vectors are filled with NaN values.
// *
// */
//void cec2006::initialize_best(void)
//{
//    double nan = std::numeric_limits<double>::quiet_NaN();

//    // the decision vector size is not known
//    m_best_known_decision_vector.resize(1);
//    m_best_known_constraint_vector.resize(m_c_dimension);
//    m_best_known_fitness_vector.resize(m_f_dimension);

//    // by default sets the vectors with nan values
//    std::fill(m_best_known_decision_vector.begin(),m_best_known_decision_vector.end(),nan);
//    std::fill(m_best_known_constraint_vector.begin(),m_best_known_constraint_vector.end(),nan);
//    std::fill(m_best_known_fitness_vector.begin(),m_best_known_fitness_vector.end(),nan);
//}

}} //namespaces

BOOST_CLASS_EXPORT_IMPLEMENT(pagmo::problem::cec2006);
