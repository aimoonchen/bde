// bbldcu_psa30360eom.h                                               -*-C++-*-
#ifndef INCLUDED_BBLDCU_PSA30360EOM
#define INCLUDED_BBLDCU_PSA30360EOM

#ifndef INCLUDED_BSLS_IDENT
#include <bsls_ident.h>
#endif
BSLS_IDENT("$Id: $")

//@PURPOSE: Provide support for PSA 30/360 end-of-month day-count convention.
//
//@CLASSES:
//  bbldcu::Psa30360eom: procedures for the PSA 30/360 eom day-count convention
//
//@DESCRIPTION: This component provides a namespace for pure procedures that
// manipulate dates as prescribed by the Public Securities Association (PSA)
// 30/360 day-count convention with end of month (eom) adjustments.
//..
//                      PSA 30/360-eom Day-Count Algorithm
//                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Given 'beginDate' and 'endDate' let:
//
// Ye =  year of earlier date           Yl =  year of later date
// Me = month of earlier date           Ml = month of later date
// De =   day of earlier date           Dl =   day of later date
//
//   o If De is the last day of February (29 in a leap year, else 28),
//     change De to 30.
//
//   o If De is 31, change De to 30.
//
//   o If at this point De is 30 and Dl is 31, change Dl to 30.
//
// daysDiff ::= sign(endDate - beginDate) *
//                           max((Yl - Ye) * 360 + (Ml - Me) * 30 + Dl - De, 0)
//..
// The max() function is required because Dl has no February adjustment and
// simple diffs like (19990228 - 19990228) produce -2 without max().
//
// Ref: PSA Standard Formulas, page SF-17
//
///Usage
///-----
// The following snippets of code illustrate how to use 'bbldcu::Psa30360eom'
// methods.  First, create two 'bdlt::Dates' 'd1' and 'd2':
//..
//  const bdlt::Date d1(2004,  9, 30);
//  const bdlt::Date d2(2004, 12, 31);
//..
// To compute the day-count between these two dates:
//..
//  const int daysDiff = bbldcu::Psa30360eom::daysDiff(d1, d2);
//  assert(90 == daysDiff);
//..
// To compute the year fraction between these two dates:
//..
//  const double yearsDiff = bbldcu::Psa30360eom::yearsDiff(d1, d2);
//  assert(0.25 == yearsDiff);
//..

#ifndef INCLUDED_BBLSCM_VERSION
#include <bblscm_version.h>
#endif

namespace BloombergLP {

namespace bdlt {

class Date;

}  // close namespace bdlt

namespace bbldcu {

                           // ==================
                           // struct Psa30360eom
                           // ==================

struct Psa30360eom {
    // This 'struct' provides a namespace for pure procedures determining
    // values based on dates according to the PSA 30/360 end-of-month day-count
    // convention.

    // CLASS METHODS
    static int daysDiff(const bdlt::Date& beginDate,
                        const bdlt::Date& endDate);
        // Return the number of days between the specified 'beginDate' and
        // 'endDate' according to the PSA 30/360 end-of-month day-count
        // convention.  If 'beginDate <= endDate', then the result is
        // non-negative.  Note that reversing the order of 'beginDate' and
        // 'endDate' negates the result.

    static double yearsDiff(const bdlt::Date& beginDate,
                            const bdlt::Date& endDate);
        // Return the number of years between the specified 'beginDate' and
        // 'endDate' according to the PSA 30/360 end-of-month day-count
        // convention.  If 'beginDate <= endDate', then the result is
        // non-negative.  Note that reversing the order of 'beginDate' and
        // 'endDate' negates the result.
};

}  // close package namespace
}  // close enterprise namespace

#endif

// ----------------------------------------------------------------------------
// Copyright 2015 Bloomberg Finance L.P.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ----------------------------- END-OF-FILE ----------------------------------