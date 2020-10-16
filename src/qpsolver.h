#ifndef __QPSOLVER_H__
#define __QPSOLVER_H__

#include <stdbool.h>
#include "matrix.h"

enum {
	QP_SUCCESS_SOLVED,
	QP_ERROR_NO_OPTIMIZATION_VARIABLE,
	QP_ERROR_NO_OBJECTIVE_FUNCTION,
	QP_ERROR_INCOMPLETE_EQUAILITY_CONSTRAINT
} QP_RETURN_STATE;

typedef struct {
	/* optimization variable */
	vector_t *x;

	/* cost function */
	matrix_t *P;
	vector_t *q;
	vector_t *r;

	/* equality constraint */
	matrix_t *A;
	vector_t *b;

	/* inequality constraints */
	vector_t *lb;
	vector_t *ub;
} qp_t;

void qp_solve_set_optimization_variable(qp_t *qp, vector_t *x);
void qp_solve_set_cost_function(qp_t *qp, matrix_t *P, vector_t *q, vector_t *r);
void qp_solve_set_equality_constraints(qp_t *qp, matrix_t *A, vector_t *b);
void qp_solve_set_upper_bound_inequality_constraints(qp_t *qp, vector_t *ub);
void qp_solve_set_lower_bound_inequality_constraints(qp_t *qp, vector_t *lb);
int qp_solve_start(qp_t *qp);

#endif